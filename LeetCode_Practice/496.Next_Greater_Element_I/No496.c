// https://leetcode.com/problems/next-greater-element-i/description/

#include <stdlib.h>
#include <stdio.h>

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    *returnSize = nums1Size;
    int* output = (int*)malloc(sizeof(int)*nums1Size);
    int* stack = (int*)malloc(sizeof(int)*nums2Size);
    int top = -1;
    int nums1MappingTable[10000];

    for(int i=0; i<nums2Size; i++){
        if(top == -1){
            stack[++top] = nums2[i];
        }
        else{
            while(top!=-1 && stack[top] < nums2[i]){
                nums1MappingTable[stack[top]] = nums2[i];
                top--;
            }
            stack[++top] = nums2[i];
        }
    }
    while(top!=-1){
        nums1MappingTable[stack[top--]] = -1;
    }
    for(int i=0; i<nums1Size; i++){
        output[i] = nums1MappingTable[nums1[i]];
    }
    free(stack);
    return output;
}

int main(){
    int nums1[3] = {4, 1, 2};
    int nums2[4] = {1, 3, 4, 2};
    int returnSize;
    int* output = nextGreaterElement(nums1, 3, nums2, 4, &returnSize);

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