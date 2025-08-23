// https://leetcode.com/problems/merge-two-sorted-lists/description/

#include <stdlib.h>
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* head = NULL;
    struct ListNode* ptr = NULL;
    int select = -1;  // 1: choose list1, 2:choose list2

    while(list1!=NULL || list2!=NULL){
        if(list1 == NULL){
            select = 2;
        }
        else if(list2 == NULL){
            select = 1;
        }
        else{
            if(list1->val <= list2->val){
                select = 1;
            }
            else{
                select = 2;
            }
        }
        
        if(head == NULL){
            if(select == 1){
                head = list1;
                ptr = list1;
                list1 = list1->next;
            }
            else{
                head = list2;
                ptr = list2;
                list2 = list2->next;
            }
        }
        else{
            if(select == 1){
                ptr->next = list1;
                ptr = ptr->next;
                list1 = list1->next;
            }
            else{
                ptr->next = list2;
                ptr = ptr->next;
                list2 = list2->next;
            }
        }
    }
    return head;
}

int main(){
    struct ListNode l1[3];
    struct ListNode l2[3];

    l1[0].val = 1;
    l1[1].val = 2;
    l1[2].val = 4;
    
    l2[0].val = 1;
    l2[1].val = 3;
    l2[2].val = 4;

    for(int i=0; i<2; i++){
        l1[i].next = &l1[i+1];
        l2[i].next = &l2[i+1];
    }

    l1[2].next = NULL;
    l2[2].next = NULL;

    struct ListNode* result = mergeTwoLists(l1, l2);
    while(result != NULL){
        printf("%d ", result->val);
        result = result->next;
    }
    printf("\n");

    return 0;
}