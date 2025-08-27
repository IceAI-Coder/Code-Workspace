// https://leetcode.com/problems/implement-queue-using-stacks/description/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* front;
    Node* rear;
    int size;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->front = NULL;
    obj->rear = NULL;
    obj->size = 0;
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    Node* newData = (Node*)malloc(sizeof(Node));
    newData->data = x;
    newData->next = NULL;
    if(obj->front == NULL){
        obj->front = newData;
        obj->rear = newData;
    }
    else{
        obj->rear->next = newData;
        obj->rear = newData;
    }
    obj->size++;
}

int myQueuePop(MyQueue* obj) {
    Node* to_remove = obj->front;
    int val = to_remove->data;

    obj->front = to_remove->next;
    obj->size--;

    if(obj->front == NULL){
        obj->rear = NULL;
    }

    free(to_remove);
    return val;
}

int myQueuePeek(MyQueue* obj) {
    return obj->front->data;
}

bool myQueueEmpty(MyQueue* obj) {
    return obj->size == 0;
}

void myQueueFree(MyQueue* obj) {
    while(obj->front){
        myQueuePop(obj);
    }
    free(obj);
}

int main(){
    MyQueue* q = myQueueCreate();
    myQueuePush(q, 1);
    myQueuePush(q, 2);
    myQueuePush(q, 3);
    printf("%d\n", myQueuePeek(q));  // 1
    printf("%d\n", myQueuePop(q));   // 1
    printf("%d\n", myQueuePop(q));   // 2
    printf("%d\n", myQueueEmpty(q)); // 0
    myQueueFree(q);
    return 0;
}