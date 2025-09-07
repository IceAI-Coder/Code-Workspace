// https://leetcode.com/problems/subarray-sum-equals-k/description/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define MAX_HASH_VALUE 40001

typedef struct HASH_TABLE{
    int data;
    int count;
} HASH_TABLE;

int hash(int input){
    return (input + 10000000) % MAX_HASH_VALUE;
}

void put(HASH_TABLE* table, int data){
    int insertedIndex = hash(data);
    while(table[insertedIndex].count !=0 && table[insertedIndex].data != data){
        insertedIndex = (insertedIndex + 1) % MAX_HASH_VALUE;
    }
    table[insertedIndex].data = data;
    table[insertedIndex].count++;
}

int get(HASH_TABLE* table, int data){
    int index = hash(data);
    while(table[index].count != 0){
        if(table[index].data == data){
            return table[index].count;
        }
        else{
            index = (index + 1) % MAX_HASH_VALUE;
        }
    }
    return 0;  // not found
}

int subarraySum(int* nums, int numsSize, int k) {
    // sum[i, j] = sum[0, j] - sum[0, i]   where this value will equal  nums[i+1]+nums[i+2]+...+nums[j]
    // store the value 0 to index to each item
    // try to add front and end, since the index will not out of range

    // make HASH table
    // when see sum[0, j], try to find  sum[0, i] = sum[0, j] - k   
    HASH_TABLE *hash_Table = (HASH_TABLE*) calloc (MAX_HASH_VALUE, sizeof(HASH_TABLE));


    int sum = 0;
    int ans = 0;
    put(hash_Table, 0);  // indicate sum[0, j] itself, since i could not be -1
    for(int i=0; i<numsSize; i++){
        sum += nums[i];

        // when see sum[0, j], try to find  sum[0, i] = sum[0, j] - k
        ans+=get(hash_Table, sum - k);
        // put data into hash table
        put(hash_Table, sum);
    }

    return ans;
}

int main(){
    int nums[] = {1, 1, 1};    
    printf("%d\n", subarraySum(nums, 3, 2));  // 2

    int nums2[] = {1, 2, 3};
    printf("%d\n", subarraySum(nums2, 3, 3));  // 2

    int nums3[] = {0,0,0,0,0,0,0,0,0,0};
    printf("%d\n", subarraySum(nums3, 10, 0));  // 55
    return 0;
}