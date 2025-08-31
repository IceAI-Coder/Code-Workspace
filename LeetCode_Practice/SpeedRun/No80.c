// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150

int removeDuplicates(int* nums, int numsSize) {
    int curr = -10001;
    int count = 0;
    int outputSize = 0;

    for(int i=0; i<numsSize; i++){
        if(curr != nums[i]){
            nums[outputSize] = nums[i];
            curr = nums[i];
            count = 1;
            outputSize++;
        }
        else if(count < 2 && curr==nums[i]){
            nums[outputSize] = nums[i];
            count++;
            outputSize++;
        }
    }
    return outputSize;
}