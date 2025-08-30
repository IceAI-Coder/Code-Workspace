// https://leetcode.com/problems/container-with-most-water/

#include <stdlib.h>
#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0;
    int right = heightSize - 1;
    int max = 0;
    int area;

    // compare left and right bar
    // if(left > right), move right to left one. (Since if keep right bar, it's not possible to find more water by this condition)
    // vice versa
    for(int i=0; i<heightSize; i++){
        if(height[left] > height[right]){
            area = height[right] * (right - left);
            right--;
        }
        else{
            area = height[left] * (right - left);
            left++;
        }

        if(area > max){
            max = area;
        }
    }
    return max;
}

int main(){
    int input[9] = {1,8,6,2,5,4,8,3,7};
    printf("%d\n", maxArea(input, 9));
    return 0;
}