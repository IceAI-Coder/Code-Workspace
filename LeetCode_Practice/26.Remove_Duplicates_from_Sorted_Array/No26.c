#include <stdlib.h>
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int outputSize = 0;
    int current = -101;
    for(int i=0; i<numsSize; i++){
        if(nums[i] != current){
            current = nums[i];
            nums[outputSize] = current;
            outputSize++;
        }
    }
    return outputSize;
}

int main(){
    int nums[] = {1, 1, 2};
    int newSize = removeDuplicates(nums, 3);
    for(int i = 0; i < newSize; i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}