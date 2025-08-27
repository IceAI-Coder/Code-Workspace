// https://leetcode.com/problems/next-greater-element-ii/description/

#include <stdlib.h>
#include <stdio.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize) {
    // A circle means everyone could refer to itself again -> array will be nums + nums
    *returnSize = numsSize;

    int* output = (int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize; i++){
        output[i] = -1;
    }
    int* stack = (int*)malloc(sizeof(int)*numsSize*2);  // only save the index
    int top = -1;
    for(int i=0;i<numsSize*2; i++){
        if(top==-1){
            stack[++top] = i%numsSize;
        }
        else{
            while(top!=-1 && nums[stack[top]] < nums[i%numsSize]){
                output[stack[top]] = nums[i%numsSize];
                top--;
            }
            stack[++top] = i%numsSize;
        }
    }
    free(stack);
    return output;
}

int main(){
    int nums[3] = {1, 2, 1};
    int returnSize;
    int* output = nextGreaterElements(nums, 3, &returnSize);
    printf("[");
    for(int i=0; i<returnSize; i++){
        printf("%d", output[i]);
        if(i!=returnSize-1){
            printf(", ");
        }
    }
    printf("]\n");
    return 0;
}