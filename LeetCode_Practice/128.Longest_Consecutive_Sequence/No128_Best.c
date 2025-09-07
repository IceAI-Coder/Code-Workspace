// https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_HASH_SIZE 200003

typedef struct HASH_ELEMENT{
    bool used;
    int data;
} HASH_ELEMENT;

int hash(int input){
    unsigned int h;
    h = 0x01000193;
    h ^= (unsigned int)input + 0x9e3779b9 + (h<<6) + (h>>4);
    return h % MAX_HASH_SIZE;
}

int find(HASH_ELEMENT *table, int x){
    int index = hash(x);
    while(table[index].used && table[index].data != x){
        index = (index + 1) % MAX_HASH_SIZE;
    }

    if(table[index].used){
        return index;
    }
    else{
        return -1;
    }
}

void insert(HASH_ELEMENT *table, int x){
    int index = hash(x);
    while(table[index].used && table[index].data != x){
        index = (index + 1) % MAX_HASH_SIZE;
    }
    table[index].used = true;
    table[index].data = x;
}

int longestConsecutive(int* nums, int numsSize) {
    // 0 <= nums.length <= 10^5
    HASH_ELEMENT *hashTable = (HASH_ELEMENT*)calloc(MAX_HASH_SIZE, sizeof(HASH_ELEMENT));
    
    for(int i=0; i<numsSize; i++){
        insert(hashTable, nums[i]);
    }

    int ans = 0;
    int maxStart = 0;
    int currMax, currVal;
    for(int i=0; i<numsSize; i++){
        currMax = 0;
        currVal = nums[i];
        // find x-1 first
        // if x-1 exist, means it is not the start point, so ignore it.
        // if x-1 not exist, start to find the consecutive value

        if(ans!=0 && currVal==maxStart){
            continue;
        }

        if(find(hashTable, currVal-1) == -1){
            while(find(hashTable, currVal++) != -1){
                currMax++;
            }

            if(currMax > ans){
                ans = currMax;
                maxStart = nums[i];
            }
        }
    }
    free(hashTable);
    return ans;
}

int main(){
    int nums[] = {100,4,200,1,3,2};
    printf("%d\n", longestConsecutive(nums, 6));   // 4

    int nums1[] = {0,3,7,2,5,8,4,6,0,1};
    printf("%d\n", longestConsecutive(nums1, 10)); // 9
    return 0;
}