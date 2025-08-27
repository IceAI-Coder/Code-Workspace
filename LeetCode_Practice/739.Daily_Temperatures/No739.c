// https://leetcode.com/problems/daily-temperatures/description/

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int index;
    int data;
    struct Node* next;
}Node;

typedef struct Stack{
    Node* top;
} Stack;

int stack_pop(Stack* obj){
    int index = obj->top->index;
    Node* to_remove = obj->top;
    obj->top = to_remove->next;
    free(to_remove);
    return index;
}

void stack_push(Stack* obj, int index, int val){
    Node* newData = (Node*)malloc(sizeof(Node));
    newData->index = index;
    newData->data = val;
    newData->next = obj->top;

    obj->top = newData;
}

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    *returnSize = temperaturesSize;
    int* output = (int*)malloc(sizeof(int)*temperaturesSize);
    
    Stack* obj = (Stack*)malloc(sizeof(Stack));
    obj->top =  NULL;

    for(int i=0; i<temperaturesSize; i++){
        output[i] = 0;  //init

        // If stack empty -> push
        // Else
        //   If stack value lower then incoming value
        //     pop stack then store result foe every lower value in stack
        //   Else
        //     push stack

        if(obj->top == NULL){
            stack_push(obj, i, temperatures[i]);
        }
        else{
            while(obj->top!=NULL && obj->top->data < temperatures[i]){
                int idx = stack_pop(obj);
                output[idx] = i - idx;
            }
            stack_push(obj, i, temperatures[i]);
        }
    }
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