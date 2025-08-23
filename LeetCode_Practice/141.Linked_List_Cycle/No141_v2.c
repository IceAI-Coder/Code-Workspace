// https://leetcode.com/problems/linked-list-cycle/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    
    int step = 0;
    while(fast != NULL){
        fast = fast->next;
        if(step%2 == 1){
            slow = slow->next;
        }
        if(fast == slow){
            return true;
        }
        step++;
    }
    return false;
}

int main(){
    struct ListNode input[4];

    input[0].val = 3;
    input[1].val = 2;
    input[2].val = 0;
    input[3].val = -4;
    input[0].next = &input[1];
    input[1].next = &input[2];
    input[2].next = &input[3];
    input[3].next = &input[1];

    printf("%B\n", hasCycle(input));

    return 0;
}