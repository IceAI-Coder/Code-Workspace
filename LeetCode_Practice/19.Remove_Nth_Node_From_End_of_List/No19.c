// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Find the size of ListNode
    int size = 0;
    struct ListNode* ptr = head;
    while(ptr != NULL){
        size++;
        ptr = ptr->next;
    }

    if(size == 1 && n==1){
        return NULL;
    }

    if(size == n){
        return head->next;
    }

    ptr = head;
    for(int i=0; i<size-n-1; i++){
        ptr = ptr->next;
    }

    ptr->next = ptr->next->next;
    return head;
}

int main(){
    struct ListNode input[5];
    for(int i=0; i<5; i++){
        input[i].val = i+1;
        
        if(i!=4){
            input[i].next = &input[i+1];
        }
        else{
            input[i].next = NULL;
        }
    }
    struct ListNode* output = removeNthFromEnd(&input[0], 2);
    while(output!=NULL){
        printf("%d ", output->val);
        output = output->next;
    }
    printf("\n");
}