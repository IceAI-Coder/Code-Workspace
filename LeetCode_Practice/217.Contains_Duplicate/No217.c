// https://leetcode.com/problems/contains-duplicate/description/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define HASH_TABLE_MAX 100003  // Since the problem will have only 10^5 numsSize.

// Following the problems, 1 <= nums.length <= 10^5
typedef struct Node{
    int key;
    bool used;
}Node;

bool containsDuplicate(int* nums, int numsSize) {
    Node* hashTable = (Node*)calloc(HASH_TABLE_MAX, sizeof(Node));

    int modResult;
    for(int i=0; i<numsSize; i++){
        modResult = (nums[i] % HASH_TABLE_MAX + HASH_TABLE_MAX)%HASH_TABLE_MAX;  // Since abs will duplicate collision, this shall be prevented.
        while(hashTable[modResult].used){
            if(hashTable[modResult].key == nums[i]){
                free(hashTable);
                return true;
            }
            modResult = (modResult + 1) % HASH_TABLE_MAX;
        }
        hashTable[modResult].key = nums[i];
        hashTable[modResult].used = true;
    }
    free(hashTable);
    return false;
}

int main(){
    int nums[4] = {-1, 1, 2, -1};
    printf("%d\n", containsDuplicate(nums,4));
    return 0;
}