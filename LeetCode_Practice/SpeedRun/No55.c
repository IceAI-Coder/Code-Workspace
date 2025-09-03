#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    if(numsSize == 1){
        return true;
    }
    int maxPosCanBeReach = 0;  // target will be numsSize-1

    for(int i=0; i<numsSize-1; i++){
        if(maxPosCanBeReach < i){
            return false;
        }
        
        if(i+nums[i] > maxPosCanBeReach){
            maxPosCanBeReach = i + nums[i];
            
        }
        if(maxPosCanBeReach >= numsSize-1){
            break;
        }
    }
    if(maxPosCanBeReach >= numsSize-1){
        return true;
    }
    else{
        return false;
    }

}

int main(){
    int nums[5] = {3,2,1,0,4};
    printf("%d\n", canJump(nums, 5));
    return 0;
}