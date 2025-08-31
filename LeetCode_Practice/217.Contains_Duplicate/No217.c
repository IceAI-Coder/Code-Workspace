// https://leetcode.com/problems/contains-duplicate/description/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define HASH_TABLE_MAX 100003  // Since the problem will have only 10^5 numsSize.

typedef struct Node{
    int data;
    struct Node* next;
}Node;

bool containsDuplicate(int* nums, int numsSize) {
    Node* hashTable[HASH_TABLE_MAX];
    for(int i=0; i<HASH_TABLE_MAX; i++){
        hashTable[i] = NULL;
    }

    int modResult;
    Node* newData;
    Node* ptr;
    for(int i=0; i<numsSize; i++){
        modResult = abs(nums[i]) % 100003;
        newData = (Node*)malloc(sizeof(Node));
        newData->data = nums[i];
            
        if(hashTable[modResult] == NULL){
            newData->next = NULL;   
            hashTable[modResult] = newData;
        }
        else{
            // Insert first then compare if duplicate
            newData->next = hashTable[modResult];
            hashTable[modResult] = newData;
            ptr = newData->next;
            while(ptr!=NULL){
                if(nums[i]==ptr->data){
                    return true;
                }
                ptr = ptr->next;
            }
        }
    }

    return false;
}

int main(){
    int nums[4] = {-1, 1, 2, -1};
    printf("%d\n", containsDuplicate(nums,4));
    return 0;
}