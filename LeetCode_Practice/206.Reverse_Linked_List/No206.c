#include <stdlib.h>
#include <stdio.h>
 
struct ListNode {
   int val;
   struct ListNode *next;
};
 
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* newData = NULL;
    struct ListNode* ptr = NULL;
    while(head != NULL){
        newData = (struct ListNode*)malloc(sizeof(struct ListNode));
        newData->val = head->val;
        
        if(ptr == NULL){
            ptr = newData;
            newData->next = NULL;
        }
        else{
            newData->next = ptr;
            ptr = newData;
        }
        
        head = head->next;
    }
    return ptr;
}

int main(){
    struct ListNode input[5];
    for(int i=0; i<5; i++){
        input[i].val = i;
        
        if(i!=4){
            input[i].next = &input[i+1];
        }
        else{
            input[i].next = NULL;
        }
    }
    struct ListNode* output = reverseList(&input[0]);
    while(output!=NULL){
        printf("%d ", output->val);
        output = output->next;
    }
    printf("\n");
    return 0;
}