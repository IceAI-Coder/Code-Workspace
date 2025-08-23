// https://leetcode.com/problems/linked-list-cycle-ii/

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
    struct ListNode* hitPt = head;
    
    while(fast != NULL){
        if(fast -> next != NULL){
            fast = fast -> next -> next;
            slow = slow -> next;
        }
        else{
            return NULL;
        }
        
        if(slow == fast){
            hitPt = slow;
            // pure circle evaluation
            fast = fast -> next;
            while(fast != hitPt){
                if(fast == head){
                    return head;
                }
                fast = fast->next;
            }
            // line with circle
            fast = hitPt;
            slow = head;
            while(fast != slow){
                fast = fast->next;
                slow = slow->next;
            }
            return slow;
        }      
    }
    return NULL;
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