// https://leetcode.com/problems/group-anagrams/description/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define HASH_SEED 10007  // 1 <= strs.length <= 10^4

typedef struct hashElement{
    struct hashElement* next;
    char* data_ptr;          // point to the *strs
} hashElement;

typedef struct hashList{
    hashElement* HEAD;
    int listSize;
}hashList;

// Time Complexity O(char length)
bool isAnagrams(const char* a, const char* b){
    int alphabetStore[26], idx;
    for(int i=0; i<26; i++){
        alphabetStore[i] = 0;
    }
    while(*a != '\0'){
        alphabetStore[*a++ - 'a']++;
    }
    while(*b != '\0'){
        idx = *b - 'a';
        alphabetStore[idx]--;
        if(alphabetStore[idx] < 0){
            return false;
        }
        b++;
    }
    for(int i=0; i<26; i++){
        if(alphabetStore[i] != 0){
            return false;
        }
    }
    return true;
}


int hash(const char* a){
    // formula 
    // output = (char length) * sum(char)
    int len = 0;
    int output = 0;
    while(a[len] != '\0'){
        output+= a[len] - 'a' + 1;  // plus 1 to let a have more impact for output
        len++;
    }
    return (output * len) % HASH_SEED;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    hashList* hashTable = (hashList*)calloc(HASH_SEED, sizeof(hashList));
    *returnSize = 0;

    int insertIndex;
    for(int i=0; i<strsSize; i++){
        insertIndex = hash(strs[i]);
        while(hashTable[insertIndex].HEAD != NULL){
            if(isAnagrams(strs[i], hashTable[insertIndex].HEAD->data_ptr)){
                break;
            }
            insertIndex++;
        }
        // insert
        if(hashTable[insertIndex].HEAD == NULL){
            (*returnSize)++;
        }
        hashElement* newData = (hashElement*)malloc(sizeof(hashElement));
        newData->data_ptr = strs[i];
        newData->next = hashTable[insertIndex].HEAD;
        hashTable[insertIndex].HEAD = newData;
        hashTable[insertIndex].listSize++;
    }

    for(int i=0; i<HASH_SEED; i++){
        if(hashTable[i].listSize > 0){
            hashElement* ptr;
            ptr = hashTable[i].HEAD;
            printf("[i=%d]  ", i);
            while(ptr!=NULL){
                printf("%s, ", ptr->data_ptr);
                ptr = ptr->next;
            }
            printf("\n");
        }
    }





    // char*   point to string
    // char**  point to string array
    // char*** point to array of string array
    char*** output = (char***)malloc(sizeof(char**)*(*returnSize));
    char**  outputStringArray;

    // int*   point to int
    // int**  point to int array
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    int count = 0;
    hashElement* ptr;
    for(int i=0; i<HASH_SEED; i++){
        if(hashTable[i].listSize > 0){
            (*returnColumnSizes)[count] = hashTable[i].listSize;

            ptr = hashTable[i].HEAD;
            outputStringArray = (char**)malloc(sizeof(char*)*(hashTable[i].listSize));
            for(int j=0; j<hashTable[i].listSize; j++){
                outputStringArray[j] = ptr->data_ptr;
                ptr = ptr->next;
            }
            output[count] = outputStringArray;
            count++;
        }
    }
    return output;
}

int main(){
    char* subStr;
    char** str = (char**)malloc(sizeof(char*)*6);
    subStr = (char*)malloc(sizeof(char)*3);
    subStr = "eat";
    str[0] = subStr;

    subStr = (char*)malloc(sizeof(char)*3);
    subStr = "tea";
    str[1] = subStr;

    subStr = (char*)malloc(sizeof(char)*3);
    subStr = "tan";
    str[2] = subStr;

    subStr = (char*)malloc(sizeof(char)*3);
    subStr = "ate";
    str[3] = subStr;

    subStr = (char*)malloc(sizeof(char)*3);
    subStr = "nat";
    str[4] = subStr;

    subStr = (char*)malloc(sizeof(char)*3);
    subStr = "bat";
    str[5] = subStr;

    int returnSize = 0;
    int* returnColumnSizes;
    char*** output = groupAnagrams(str,6, &returnSize, &returnColumnSizes);

    printf("%d\n", returnSize);
    for(int i=0; i<returnSize; i++){
        printf("returnColumnSizes = %d\n", returnColumnSizes[i]);
    }

    for(int i=0; i<returnSize; i++){
        printf("[");
        for(int j=0; j<returnColumnSizes[i]; j++){
            printf("\"%s\"", output[i][j]);
            if(j!=returnColumnSizes[i]-1){
                printf(", ");
            }
        }
        printf("]\n");
    }
    return 0;
}