// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <stdlib.h>
#include <stdio.h>

// by CHATGPT
// 用單調遞增 stack，裡面存 index。
// 當遇到一個比 stack top 小的高度，就一直 pop，並計算以「被 pop 出的高度」為最矮柱子的矩形。
// 寬度 = i - stack[top] - 1（右邊界是 i-1，左邊界是 pop 後 stack[top]）
// 面積 = height * 寬度
// 跑完整個 heights 後，stack 裡可能還有 index，最後再清算一次。

int largestRectangleArea(int* heights, int heightsSize) {
    int* stack = (int*)malloc(sizeof(int)*(heightsSize+1));  //Fill 0 in the end
    int top = -1;
    int currentHeight = 0;
    int leftBoundary;
    int rightBoundary;
    int max = 0;
    int currentRectArea = 0;
    for (int i=0; i<=heightsSize; i++){
        if(i==heightsSize){
            currentHeight = 0;
        }
        else{
            currentHeight = heights[i];
        }
        while(top!=-1 && currentHeight < heights[stack[top]]){
            rightBoundary = i;
            if(top==0){
                leftBoundary = -1;
            }
            else{
                leftBoundary = stack[top-1];
            }
            currentRectArea = heights[stack[top]] * (rightBoundary - leftBoundary - 1);
            if(max < currentRectArea){
                max = currentRectArea;
            }
            top--;
        }
        stack[++top] = i;
    }
    free(stack);
    return max;
}

int main(){
    int input1[6] = {2, 1, 5, 6, 2, 3};
    printf("%d\n", largestRectangleArea(input1, 6));  // 10
    int input2[2] = {2, 4};
    printf("%d\n", largestRectangleArea(input2, 2));  // 4
    return 0;
}