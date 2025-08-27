// https://leetcode.com/problems/min-stack/

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int val;
    struct Node* prev;
} Node;

typedef struct {
    Node* topNode;
    Node* minNode;
    int top;
    int minValue;
} MinStack;

MinStack* minStackCreate() {
    MinStack* output = (MinStack*)malloc(sizeof(MinStack));
    output->topNode = NULL;
    output->minNode = NULL;
    output->top = -1;
    output->minValue = -1;  // follow the question, the minValue will not be call when stack is empty. It will be update later.
    return output;
}

void minStackPush(MinStack* obj, int val) {
    // Setup node
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->prev = obj->topNode;
    // Update obj
    if(obj->top == -1){
        obj->minNode = node;
        obj->minValue = val;
    }
    else{
        if(val < obj->minValue){
            obj->minNode = node;
            obj->minValue = val;
        }
    }
    obj->topNode = node;
    obj->top++;
}

void minStackPop(MinStack* obj) {
    // Not sure what is O(1) solution at this moment... #TODO

    Node* to_remvoe = obj->topNode;
    obj->topNode = to_remvoe->prev;
    free(to_remvoe);
    obj->top--;
    // need to recaculate minValue
    if(to_remvoe == obj->minNode && obj->top!=-1){
        Node* curr = obj->topNode;
        obj->minValue = curr->val;
        obj->minNode = curr;
        while(curr != NULL){
            if(curr->val < obj->minValue){
                obj->minValue = curr->val;
                obj->minNode = curr;
            }
            curr = curr->prev;
        }
    }
}

int minStackTop(MinStack* obj) {
    return obj->topNode->val;
}

int minStackGetMin(MinStack* obj) {
    return obj->minValue;
}

void minStackFree(MinStack* obj) {
    while(obj->top != -1){
        minStackPop(obj);
    }
    free(obj);
}


int main(){
    MinStack* obj = minStackCreate();
    minStackPush(obj, 5); 
    int param_3 = minStackTop(obj);
    int param_4 = minStackGetMin(obj);
    minStackPop(obj); 
    printf("%d\n", param_3);  // 5
    printf("%d\n", param_4);  // 5

    minStackFree(obj);
    return 0;
}