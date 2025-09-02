// https://leetcode.com/problems/group-anagrams/description/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Issue#1 Hash function to weak. 
//  - Change to FNV hash (https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function)
//  - Use golden value (https://stackoverflow.com/questions/4948780/magic-number-in-boosthash-combine)
// Issue#2 Hash table size to close strs.length will cause O(n^2) when finding
// Issue#3 Need to free hash table and so on

#define HASH_TABLE_SIZE 20003 // 1 <= strs.length <= 10^4

typedef struct Node{
    struct Node* next;
    char* data;
    int sig[26];
} Node;

typedef struct Hash_Table{
    Node* HEAD;
    int listSize;
} Hash_Table;

void caculate_26_Signature(const char* input, int sig[26]){
    memset(sig, 0, sizeof(int)*26);
    while(*input){
        sig[*input++ - 'a']++;
    }
}

bool is_SignatureMatch(int sig1[26], int sig2[26]){
    for(int i=0; i<26; i++){
        if(sig1[i] != sig2[i]){
            return false;
        }
    }
    return true;
}

int caculate_hash(int sig[26]){
    unsigned h = 0x01000193;  // FNV_offset_basis
    for(int i=0; i<26; i++){
        h ^= (unsigned)sig[i] + 0x9e3779b9 + (h<<6) + (h>>4);  // Golden value for seed. Use <<6 & >>4 for high/low byte mix
    }
    return h % HASH_TABLE_SIZE;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes) {
    Hash_Table* hashTable = (Hash_Table*)calloc(HASH_TABLE_SIZE, sizeof(Hash_Table));
    *returnSize = 0;

    Node* nodeElement;
    int insertIndex;
    for(int i=0; i<strsSize; i++){
        nodeElement = (Node*)malloc(sizeof(Node));
        nodeElement->data = strs[i];
        caculate_26_Signature(nodeElement->data, nodeElement->sig);
        insertIndex = caculate_hash(nodeElement->sig);
        while(hashTable[insertIndex].HEAD != NULL){
            // this hash value already used
            if(is_SignatureMatch(hashTable[insertIndex].HEAD->sig, nodeElement->sig)){
                break;
            }
            // HASH Value Collision so plus 1
            insertIndex = (insertIndex + 1 ) % HASH_TABLE_SIZE;
        }
        if(hashTable[insertIndex].HEAD == NULL){
            (*returnSize)++;
        }
        nodeElement->next = hashTable[insertIndex].HEAD;
        hashTable[insertIndex].HEAD = nodeElement;
        hashTable[insertIndex].listSize++;
    }    

    char*** output = (char***)malloc(sizeof(char**)*(*returnSize));
    *returnColumnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    int count = 0;   // sync for *returnSize
    int count2 = 0;  // sync for ** returnColumnSizes
    Node* ptr;       // point to the data would like to store to output
    for(int i=0; i<HASH_TABLE_SIZE; i++){
        if(hashTable[i].listSize != 0){
            count2 = 0;

            ptr = hashTable[i].HEAD;            
            (*returnColumnSizes)[count] = hashTable[i].listSize;
            output[count] = (char**)malloc(sizeof(char*)*hashTable[i].listSize);
            while(ptr!=NULL){
                output[count][count2++] = ptr->data;
                hashTable[i].HEAD = hashTable[i].HEAD->next;
                free(ptr);
                ptr = hashTable[i].HEAD;
            }
            count++;
        }
    }
    return output;
}

int main() {
    char* str[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int strsSize = sizeof(str) / sizeof(str[0]);

    int returnSize = 0;
    int* returnColumnSizes;
    char*** output = groupAnagrams(str, strsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("\"%s\"", output[i][j]);
            if (j != returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
        free(output[i]);
    }
    free(output);
    free(returnColumnSizes);
    return 0;
}