// https://leetcode.com/problems/two-sum/description/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define HASH_MAX 10007

typedef struct Node{
    int index;
    int value;
    bool used;
} Node;

int getHashResult(int input){
    return (input % HASH_MAX + HASH_MAX) % HASH_MAX;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* output = (int*)malloc(sizeof(int)*2);
    
    Node* hashTable = calloc(sizeof(Node), HASH_MAX);
    // Find nums[i] in current HASH table first, if not found, insert the complement
    int hashIndex;
    for(int i=0; i<numsSize; i++){
        // Find
        hashIndex = getHashResult(nums[i]);
        while(hashTable[hashIndex].used){
            if(hashTable[hashIndex].value == nums[i]){
                output[0] = hashTable[hashIndex].index;
                output[1] = i;
                free(hashTable);
                return output;
            }
            hashIndex++;
        }
        // Insert complement
        hashIndex = getHashResult(target - nums[i]);
        while(hashTable[hashIndex].used){
            hashIndex = (hashIndex + 1)%HASH_MAX;
        }
        hashTable[hashIndex].value = target - nums[i];
        hashTable[hashIndex].index = i;
        hashTable[hashIndex].used = true;
    }
    free(hashTable);
    return output;
}

int main(){
    int nums[4] = {2, 7, 11, 15};
    int returnSize = 0;
    int* output = twoSum(nums, 4, 9, &returnSize);
    printf("%d, %d\n", output[0], output[1]);

    return 0;
}