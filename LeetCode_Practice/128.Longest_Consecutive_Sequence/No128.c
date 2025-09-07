// https://leetcode.com/problems/longest-consecutive-sequence/description/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define MAX_HASH_SIZE 200003

typedef struct HASH_ELEMENT{
    bool used;
    int data;
    int left;
    int right;
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

int insert(HASH_ELEMENT *table, int x){
    if(find(table, x) != -1){
        return -1;
    }
    
    // return max length
    int index = hash(x);
    while(table[index].used){
        index = (index + 1) % MAX_HASH_SIZE;
    }
    table[index].used = true;
    table[index].data = x;

    int l_index = find(table, x-1);
    int r_index = find(table, x+1);

    int left, right;
    if(l_index != -1 && r_index != -1){
        left = table[l_index].left;
        right = table[r_index].right;

        table[find(table, left)].right = right;
        table[find(table, right)].left = left;
    }
    else if(l_index != -1 && r_index == -1){
        left = table[l_index].left;
        right = x;

        table[find(table, left)].right = right;
        table[index].left = left;
        table[index].right = right;
    }
    else if(l_index == -1 && r_index != -1){
        left = x;
        right = table[r_index].right;
        
        table[find(table, right)].left = left;
        table[index].left = left;
        table[index].right = right;
    }
    else{
        left = x;
        right = x;
        table[index].left = x;
        table[index].right = x;
    }
    return right - left + 1;
}

int longestConsecutive(int* nums, int numsSize) {
    // 0 <= nums.length <= 10^5
    HASH_ELEMENT *hashTable = (HASH_ELEMENT*)calloc(MAX_HASH_SIZE, sizeof(HASH_ELEMENT));

    int ans = 0;

    int currMax;
    for(int i=0; i<numsSize; i++){
        currMax = insert(hashTable, nums[i]);
        if(currMax > ans){
            ans = currMax;
        }
    }
    return ans;
}

int main(){
    int nums[] = {100,4,200,1,3,2};
    printf("%d\n", longestConsecutive(nums, 6));   // 4

    int nums1[] = {0,3,7,2,5,8,4,6,0,1};
    printf("%d\n", longestConsecutive(nums1, 10)); // 9
    return 0;
}