#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    int sum = 0;  
    
    struct ListNode* HEAD = NULL;
    struct ListNode* ptr = NULL;
    struct ListNode* newData = NULL;

    while(l1 != NULL || l2 != NULL || carry!=0){
        sum = carry;
        if(l1 != NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL){
            sum += l2->val;
            l2 = l2->next;
        }
        carry = sum / 10;
        sum = sum % 10;
        
        newData = (struct ListNode*) malloc (sizeof(struct ListNode));
        newData->val = sum;
        newData->next = NULL;
        if(HEAD == NULL){
            HEAD = newData;
            ptr = newData;
        }
        else{
            ptr->next = newData;
            ptr = ptr-> next;
        }
    }
    return HEAD;
}

void freeListNode(struct ListNode* input){
    struct ListNode* ptr;
    while(ptr != NULL){
        ptr = input->next;
        free(input);
        input = ptr;
    }
}

void printListNode(struct ListNode* input){
    struct ListNode* ptr = input;
    while(ptr != NULL){
        printf("%d->", ptr->val);
        ptr = ptr -> next;
    }
    printf("NULL\n");
}

int main()
{
    struct ListNode* l1_head;
    struct ListNode* l2_head;
    struct ListNode* l1_ptr;
    struct ListNode* l2_ptr;

    l1_ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_ptr = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_head = l1_ptr;
    l2_head = l2_ptr;

    l1_ptr->val = 5;
    l1_ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_ptr = l1_ptr->next;
    l1_ptr->val = 6;
    l1_ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l1_ptr = l1_ptr->next;
    l1_ptr->val = 4;
    l1_ptr->next = NULL;
    
    l2_ptr->val = 7;
    l2_ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_ptr = l2_ptr->next;
    l2_ptr->val = 0;
    l2_ptr->next = (struct ListNode*)malloc(sizeof(struct ListNode));
    l2_ptr = l2_ptr->next;
    l2_ptr->val = 8;
    l2_ptr->next = NULL;
    
    printListNode(l1_head);
    printListNode(l2_head);

    struct ListNode* result = addTwoNumbers(l1_head, l2_head);
    printListNode(result);
    
    freeListNode(l1_head);
    freeListNode(l2_head);
    freeListNode(result);
}