// https://leetcode.com/problems/remove-duplicates-from-sorted-array/?envType=study-plan-v2&envId=top-interview-150

int removeDuplicates(int* nums, int numsSize) {
    int curr = nums[0];
    int ptr = 0;
    int last = 1;
    while(last < numsSize){
        if(curr != nums[last]){
            nums[++ptr] = nums[last];
            curr = nums[last];
        }
        last++;
    }
    
    return ptr+1;
}