// https://leetcode.com/problems/min-stack/

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int data;
    struct Node* next;  // Fix Issue#1: It seems normally, even it point to previous node. Since that featuer is most similar like point to next node, the variable name shall be next;
    struct Node* prevMinNode;  // Add the feature to maintain the minNode list. If min node be pop out, could refer to prevMin.
} Node;

typedef struct {
    // Maintain top information
    Node* top;
    // Maintain min information
    Node* minNode; // To store the latest min node info.
} MinStack;

MinStack* minStackCreate() {
    MinStack* output = (MinStack*)malloc(sizeof(MinStack));
    output->top = NULL;
    output->minNode = NULL;
    return output;
}

void minStackPush(MinStack* obj, int val) {
    // Setup newNode
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = obj->top;
    newNode->prevMinNode = NULL;

    // Update minNode info.
    if(obj->top == NULL || obj->minNode->data >= val){  // using equal to avoid the local min is maintained. e.g. [1, 0, 0] -> pop -> [1, 0]
        newNode->prevMinNode = obj->minNode;
        obj->minNode = newNode;
    }
    // Update top info.
    obj->top = newNode;
}

void minStackPop(MinStack* obj) {
    Node* to_remove = obj->top;
    // Update minNode info.
    if(to_remove->prevMinNode != NULL){
        obj->minNode = to_remove->prevMinNode;
    }
    // Update top info.
    obj->top = to_remove->next;

    free(to_remove);
}

int minStackTop(MinStack* obj) {
    return obj->top->data;
}

int minStackGetMin(MinStack* obj) {
    return obj->minNode->data;
}

void minStackFree(MinStack* obj) {
    while(obj->top){
        minStackPop(obj);
    }
    free(obj);
}


int main(){
    MinStack* obj = minStackCreate();
    minStackPush(obj, 5); // [5]
    minStackPush(obj, 3); // [5, 3]
    printf("%d\n", minStackGetMin(obj));  // 3
    minStackPush(obj, 1); // [5, 3 ,1]
    printf("%d\n", minStackGetMin(obj));  // 1
    minStackPush(obj, 3); // [5, 3 ,1, 3]
    printf("%d\n", minStackGetMin(obj));  // 1
    minStackPush(obj, 1); // [5, 3 ,1, 3, 1]
    printf("%d\n", minStackGetMin(obj));  // 1

    minStackPop(obj);  // [5, 3 ,1, 3]
    printf("%d\n", minStackTop(obj));     // 3
    printf("%d\n", minStackGetMin(obj));  // 1

    minStackFree(obj);
    return 0;
}