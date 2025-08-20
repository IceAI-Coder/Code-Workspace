/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* output = (int*) malloc(2 * sizeof(int));
    *returnSize = 2;
    for(int i=0; i<numsSize; i++){
        for(int j=i+1; j<numsSize; j++){
            if(nums[i]+nums[j] == target){
                output[0] = i;
                output[1] = j;
                return output;
            }
        }
    }
    return output;
}

int main(){
    int nums[4] = {2, 7, 11, 15};
    int* output;
    int returnSize;
    
    output = twoSum(nums, 4, 9, &returnSize);

    printf("[%d, %d]\n", output[0], output[1]);
    free(output);
    return 0;
}