// https://leetcode.com/problems/subarray-sum-equals-k/description/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_HASH_VALUE 40001

typedef struct HASH_ELEMENT{
    struct HASH_ELEMENT *next;
    int index;
    int data;
} HASH_ELEMENT;

typedef struct HASH_TABLE{
    struct HASH_ELEMENT *HEAD;
} HASH_TABLE;

int hash(int input){
    return (input + 10000000) % MAX_HASH_VALUE;
}

int subarraySum(int* nums, int numsSize, int k) {
    // sum[i, j] = sum[0, j] - sum[0, i]   where this value will equal  nums[i+1]+nums[i+2]+...+nums[j]
    // store the value 0 to index to each item
    // try to add front and end, since the index will not out of range
    int sum = 0;
    for(int i=0; i<numsSize; i++){
        sum += nums[i];
        nums[i]= sum;
    }

    // make HASH table
    // when find sum[0, i], searching if there's a value for sum[0, j]
    HASH_TABLE *hash_Table = (HASH_TABLE*) calloc (MAX_HASH_VALUE, sizeof(HASH_TABLE));
    HASH_ELEMENT *hash_Element = (HASH_ELEMENT*) calloc (numsSize, sizeof(HASH_ELEMENT));
    int hash_Element_cnt = 0;  // this value will point to the latest element which need to write in

    int insertedIndex;
    for(int i=0 ;i<numsSize; i++){
        insertedIndex = hash(nums[i]);
        while(hash_Table[insertedIndex].HEAD != NULL && hash_Table[insertedIndex].HEAD->data != nums[i]){
            insertedIndex = (insertedIndex + 1) % MAX_HASH_VALUE;
        }
        
        hash_Element[hash_Element_cnt].index = i;
        hash_Element[hash_Element_cnt].data = nums[i];
        hash_Element[hash_Element_cnt].next = hash_Table[insertedIndex].HEAD;
        hash_Table[insertedIndex].HEAD = &hash_Element[hash_Element_cnt];

        hash_Element_cnt++;
    }

    // when see sum[0, i], try to find  sum[0, j] =  k + sum[0, i],   
    // Note: i shall not equal j
    // Note: final answer shall be deived by 2, since i, j could be swap
    int ans = 0;
    int targetValue;
    int targetHashIndex;
    HASH_ELEMENT *currHashElementPtr;
    for(int i=0; i<numsSize; i++){
        if(nums[i] == k){
            ans++;
        }
        targetValue = k + nums[i];
        targetHashIndex = hash(targetValue);
        currHashElementPtr = hash_Table[targetHashIndex].HEAD;
        while(currHashElementPtr != NULL){
            if(currHashElementPtr->data != targetValue){
                currHashElementPtr = hash_Table[++targetHashIndex].HEAD;
            }
            else{
                if(currHashElementPtr->index > i){
                    ans++;
                }
                currHashElementPtr = currHashElementPtr->next;
            }
        }
    }

    free(hash_Table);
    free(hash_Element);
    return ans;
}

int main(){
    /*
    int nums[] = {1, 1, 1};    
    printf("%d\n", subarraySum(nums, 3, 2));

    int nums2[] = {1, 2, 3};
    printf("%d\n", subarraySum(nums2, 3, 3));
    */

    int nums3[] = {0,0,0,0,0,0,0,0,0,0};
    printf("%d\n", subarraySum(nums3, 10, 0));
    return 0;
}