/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
#include <stdio.h>

#define HASH_TABLE_MAX 200003

typedef struct HASH_TABLE{
    int count;
    int data;
} HASH_TABLE;

int hash(int input){
    return ( input + HASH_TABLE_MAX ) % HASH_TABLE_MAX;
}

int cmp(const void *a, const void *b){
    const int* rowA = *(const int**)a;
    const int* rowB = *(const int**)b;
    return rowA[1] - rowB[1];
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    *returnSize = k;

    // 1 <= nums.length <= 10^5
    // use HASH table
    HASH_TABLE* hashTable = (HASH_TABLE*) calloc(HASH_TABLE_MAX, sizeof(HASH_TABLE));

    // insert nums[] to hash table
    // time complexity: O(n)
    int insertedIndex;
    int num_UniqueElements = 0;
    for(int i=0; i<numsSize; i++){
        insertedIndex = hash(nums[i]);
        while(hashTable[insertedIndex].count != 0 && hashTable[insertedIndex].data != nums[i]){
            insertedIndex = (insertedIndex + 1) % HASH_TABLE_MAX;
        }
        if(hashTable[insertedIndex].count == 0){
            hashTable[insertedIndex].data = nums[i];
            hashTable[insertedIndex].count++;
            num_UniqueElements++;
        }
        else{
            hashTable[insertedIndex].count++;
        }
    }
    
    // to store result to the table
    int uniqueElement[num_UniqueElements][2];  // 0 to store value, 1 to store freq.
    int cnt = 0;
    int* ptrs[num_UniqueElements];
    for(int i=0; i<HASH_TABLE_MAX; i++){
        if(hashTable[i].count != 0){
            uniqueElement[cnt][0] = hashTable[i].data;
            uniqueElement[cnt][1] = hashTable[i].count;
            ptrs[cnt] = uniqueElement[cnt];
            cnt++;
        }
    }
    free(hashTable);

    // sort uniqueElement by count
    // Time complexity n log n
    qsort(ptrs, num_UniqueElements, sizeof(int*), cmp);

    // find k elments from right to left
    int* output = (int*)malloc(sizeof(int)*k);
    for(int i=0; i<k; i++){
        output[i] = ptrs[num_UniqueElements - 1 - i][0];
    }



    return output;
}

int main(){
    int nums[] = {3, 0, 1, 0};
    int returnSize;
    int* output = topKFrequent(nums, 4, 1, &returnSize);
    for(int i=0; i<returnSize; i++){
        printf("%d, ", output[i]);
    }
    printf("\n");

    return 0;
}