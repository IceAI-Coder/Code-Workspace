// https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150


int majorityElement(int* nums, int numsSize) {
    int idx, count;
    idx = 0;
    count = 1;
    for(int i=1; i<numsSize; i++){
        if(nums[idx] == nums[i]){
            count++;
        }
        else{
            count--;
        }
        if(count == 0){
            idx = i;
            count = 1;
        }
    }
    return nums[idx];
}