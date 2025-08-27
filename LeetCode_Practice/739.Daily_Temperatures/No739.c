// https://leetcode.com/problems/daily-temperatures/description/

#include <stdlib.h>
#include <stdio.h>

// Improve with array version, since even time complexity is O(n). It's still very slow due to malloc/free.
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;

    int* output = (int*)malloc(sizeof(int)*temperaturesSize);
    int* stack = (int*)malloc(sizeof(int)*temperaturesSize);  // Only save index
    int top = -1;

    for(int i=0; i<temperaturesSize; i++){
        output[i] = 0;  //init

        // If stack empty -> push
        // Else
        //   If stack value lower then incoming value
        //     pop stack then store result foe every lower value in stack
        //   Else
        //     push stack

        if(top == -1){
            stack[++top] = i;
        }
        else{
            while(top!=-1 && temperatures[stack[top]] < temperatures[i]){
                output[stack[top]] = i - stack[top];
                top--;
            }
            stack[++top] = i;
        }
    }
    free(stack);
    return output;
}

int main(){
    int temperatures[8] = {73, 74, 75, 71, 69, 72, 76, 73};
    int returnSize;
    int* output = dailyTemperatures(temperatures, 8, &returnSize);

    printf("[");
    for(int i=0; i<returnSize; i++){
        printf("%d", output[i]);
        if(i!=returnSize-1){
            printf(", ");
        }
    }
    printf("]\n");
    return 0;
}