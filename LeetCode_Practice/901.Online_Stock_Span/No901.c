// https://leetcode.com/problems/online-stock-span/

#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
    int index;
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int day;
} StockSpanner;


StockSpanner* stockSpannerCreate() {
    StockSpanner* output = (StockSpanner*)malloc(sizeof(StockSpanner));
    output->head = NULL;
    output->day = 0;
    return output;
}

int stockSpannerNext(StockSpanner* obj, int price) {
    // Setup node
    Node* node = (Node*)malloc(sizeof(Node));
    node->index = obj->day;
    node->value = price;

    int output;

    // monotonic stack
    // A > B > C
    // Pop
    while(obj->head != NULL && obj->head->value <= price){
        obj->head = obj->head->next;
    }    
    
    if(obj->head == NULL){
        output = node->index + 1;  // No price in the left larger then current price
    }
    else{
        output = node->index - obj->head->index;
    }
    // Push
    node->next = obj->head;

    // Setup obj
    obj->head = node;
    obj->day++;
    
    return output;
}

void stockSpannerFree(StockSpanner* obj) {
    Node* curr;
    while(obj->head!=NULL){
        curr = obj->head->next;
        free(obj->head);
        obj->head = curr;
    }
    free(obj);
}

int main(){
   StockSpanner* obj = stockSpannerCreate(); 
   printf("%d\n", stockSpannerNext(obj, 100));
   printf("%d\n", stockSpannerNext(obj, 80));
   printf("%d\n", stockSpannerNext(obj, 60));
   printf("%d\n", stockSpannerNext(obj, 70));
   printf("%d\n", stockSpannerNext(obj, 60));
   printf("%d\n", stockSpannerNext(obj, 75));
   printf("%d\n", stockSpannerNext(obj, 85));
   stockSpannerFree(obj);
   return 0;
}