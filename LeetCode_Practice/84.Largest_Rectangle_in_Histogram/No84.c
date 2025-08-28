// https://leetcode.com/problems/largest-rectangle-in-histogram/description/

#include <stdlib.h>
#include <stdio.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int* maxSizeMap = (int*)malloc(sizeof(int)*heightsSize);
    
    // To store the maximum rectangle of each index with its value
    // e.g. [2, 3, 1]  
    // - shall store [2, 2, 2] = 6 in the first array
    // - shall store [0, 3, 0] = 3 in the second array
    // - shall store [1, 1, 1] = 3 in the third array

    // So final size = left + right + itself
    // Use Monotonic Stack to save left and right

    // itself
    for(int i=0; i<heightsSize; i++){
        maxSizeMap[i] = heights[i];
    }

    // right
    int* stack = (int*)malloc(sizeof(int)*heightsSize);
    int top = -1;
    for(int i=0; i<heightsSize; i++){
        if(top == -1){
            stack[++top] = i;
        }
        else{
            while(top!=-1 && heights[i] < heights[stack[top]]){
                maxSizeMap[stack[top]] += (i-1-stack[top])*heights[stack[top]];
                top--;
            }
            stack[++top] = i;
        }
    }
    while(top!=-1){
        maxSizeMap[stack[top]] += (heightsSize-1-stack[top])*heights[stack[top]];
        top--;
    }

    // left
    top = -1;
    for(int i=heightsSize-1; i>=0; i--){
        if(top == -1){
            stack[++top] = i;
        }
        else{
            while(top!=-1 && heights[i] < heights[stack[top]]){
                maxSizeMap[stack[top]] += (stack[top]-i-1)*heights[stack[top]];
                top--;
            }
            stack[++top] = i;
        }
    }
    while(top!=-1){
        maxSizeMap[stack[top]] += stack[top]*heights[stack[top]];
        top--;
    }

    int max = 0;
    for(int i=0; i<heightsSize; i++){
        if(maxSizeMap[i] > max){
            max = maxSizeMap[i];
        }
    }

    free(stack);
    free(maxSizeMap);

    return max;
}

int main(){
    int input1[6] = {2, 1, 5, 6, 2, 3};
    printf("%d\n", largestRectangleArea(input1, 6));  // 10
    int input2[2] = {2, 4};
    printf("%d\n", largestRectangleArea(input2, 2));  // 4
    return 0;
}