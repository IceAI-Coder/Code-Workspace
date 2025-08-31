// https://leetcode.com/problems/remove-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <stdlib.h>
#include <stdio.h>

void swap(int* a, int* b){
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}


int removeElement(int* nums, int numsSize, int val) {
    int count = 0;
    for(int i=0; i<numsSize-count; i++){
        if(nums[i] == val){
            swap(&nums[i], &nums[numsSize - 1 - count]);
            i--;
            count++;
        }
    }
    return numsSize - count;
}

int main(){
    int a[8] = {0,1,2,2,3,0,4,2};
    printf("%d\n", removeElement(a, 8, 2));
    return 0;
}