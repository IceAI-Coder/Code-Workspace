// https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

int compare_integers(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int majorityElement(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare_integers);
    
    if(numsSize == 1){
        return nums[0];
    }

    int count = 1;
    int curr = nums[0];
    for(int i=1; i<numsSize; i++){
        if(nums[i] == curr){
            count++;
        }
        else{
            curr = nums[i];
            count = 1;
        }

        if(count * 2 >= numsSize){
            return nums[i];
        }
    }
    return -1;
}