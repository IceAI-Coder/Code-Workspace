int jump(int* nums, int numsSize) {
    if(numsSize == 1){
        return 0;
    }

    // O(n)
    // from 1 to nums[0] find max pos. can be reached
    // from nums[0] to max pos. ==> find next max pos. can be reached
    int step = 1;
    int preMaxPos = 1;
    int currMaxPos = nums[0];
    int nextMaxPos = nums[0];

    while(currMaxPos < numsSize - 1){
        step++;
        for(int i=preMaxPos; i<=currMaxPos; i++){
            if(nextMaxPos < nums[i] + i){
                nextMaxPos = nums[i] + i;
            }
        }
        preMaxPos = currMaxPos;
        currMaxPos = nextMaxPos;
    }
    return step;
}

int main(){
    int nums[] = {5,9,3,2,1,0,2,3,3,1,0,0};
    printf("%d\n", jump(nums, 12));
    return 0;
}