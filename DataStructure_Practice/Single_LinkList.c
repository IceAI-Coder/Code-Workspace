#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct ListNode {
    int val;
    struct ListNode* next;
} ListNode;

typedef struct LinkedList {
    ListNode* head;
    int size;
} LinkedList;

// Index Validation
bool index_validation(const LinkedList* list, int index){
    if(index < 0){
        printf("Index out of range.\n");
        return false;
    }
    if(index >= list->size){
        printf("Index out of range.\n");
        return false;
    }
    return true;
}

// Create & Delete
LinkedList* create_list();
void free_list(LinkedList* list);

// Add Node
void push_front(LinkedList* list, int value);
void push_back(LinkedList* list, int value);
void insert_at(LinkedList* list, int index, int value);

// Remove Node
void pop_front(LinkedList* list);
void pop_back(LinkedList* list);
void delete_at(LinkedList* list, int index);

// Get & Set
int get_at(LinkedList* list, int index);
int find(LinkedList* list, int value);
int is_empty(LinkedList* list);
int size(LinkedList* list);
void set_at(LinkedList* list, int index, int new_value);

// Other
void print_list(LinkedList* list);
void reverse(LinkedList* list);
LinkedList* clone_list(const LinkedList* list);

// Function Implement
#pragma region Create & Delete
LinkedList* create_list(){
    LinkedList* output = (LinkedList*)malloc(sizeof(LinkedList));  // NOTE: Please make sure even LinkedList shall be allocate to the memory space!!!
    output->head = NULL;
    output->size = 0;
    return output;
}
void free_list(LinkedList* list){
    if(list -> size == 0){
        return;
    }

    // save current & next node information
    ListNode* current = list->head;
    ListNode* ptr;  // NOTE: Always shall aware the boundary of ListNode!!!
    for(int i=0; i<list->size; i++){
        ptr = current->next;
        free(current);
        current = ptr;
    }
    list->head = NULL;
    list->size = 0;
}
#pragma endregion

#pragma region Add Node
void push_front(LinkedList* list, int value){
    // setup newData value
    ListNode* newData = (ListNode*)malloc(sizeof(ListNode));
    newData->val = value;
    newData->next = list->head;
    // setup list
    list->head = newData;
    list->size++;
}
void push_back(LinkedList* list, int value){
    // setup newData value
    ListNode* newData = (ListNode*)malloc(sizeof(ListNode));
    newData->val = value;
    newData->next = NULL;
    
    // setup list
    // find the list[size-1]
    // corner case size = 0  Issue#1
    if(list->head == NULL){
        list->head = newData;
    }
    else{
        ListNode* ptr = list->head;
        for(int i=1; i<=list->size-1; i++){
            ptr = ptr->next;
        }
        // setup last node
        ptr->next = newData;
    }
    // setup list
    list->size++;
}
void insert_at(LinkedList* list, int index, int value){
    // insert node before list[index]
    // cannot insert after list[size-1]
    // data validation first
    if(!index_validation(list, index)){
        return;
    }

    // find list[index-1] node
    // corner case index = 0
    if(index == 0){
        push_front(list, value);
        return;
    }
    ListNode* ptr = list->head;
    for(int i=0; i<index-1; i++){
        ptr = ptr->next;
    }
    
    // setup newData
    ListNode* newData = (ListNode*)malloc(sizeof(ListNode));
    newData->val = value;
    newData->next = ptr->next;

    // setup ptr
    ptr->next = newData;

    // setup list
    list->size++;
}
#pragma endregion

#pragma region Remove Node
void pop_front(LinkedList* list){
    // Data validation
    if(list->size <= 0){
        printf("Cannot pop_fron empty list. No action performed.\n");
        return;
    }

    // Save 1st node address to free
    ListNode* ptr = list->head;

    // Setup list
    list->head = list->head->next;
    list->size--;

    // free 1st node
    free(ptr);
}
void pop_back(LinkedList* list){
    // Data validation
    if(list->size <= 0){
        printf("Cannot pop_back empty list. No action performed.\n");
        return;
    }

    // find list[size-2]
    // corner case size = 1
    if(list->size == 1){
        free_list(list);
        return;
    }
    ListNode* ptr = list->head;
    for(int i=1; i<=list->size-2; i++){
        ptr = ptr->next;
    }
    
    // free list[size-1]
    free(ptr->next);
    
    // setup ptr
    ptr->next = NULL;
    
    // setup list
    list->size--;
}
void delete_at(LinkedList* list, int index){
    // delete list[index]
    if(!index_validation(list, index)){
        return;
    }
    // find list[index-1]
    // corner case index = 0
    if(index == 0){
        pop_front(list);
        return;
    }
    
    ListNode* ptr = list->head;
    for(int i=1; i<=index-1; i++){
        ptr = ptr->next;
    }
    // save list[index] to free
    ListNode* ptr_index = ptr->next;

    // setup list[index-1] -> next = list[index] -> next
    ptr->next = ptr->next->next;

    // free list[index]
    free(ptr_index);

    // setup list
    list->size--;
}
#pragma endregion

#pragma region Get & Set
int get_at(LinkedList* list, int index){
    if(!index_validation(list, index)){
        return -1;
    }

    // find list[index]
    ListNode* ptr = list->head;
    for(int i=0;i<index; i++){
        ptr = ptr->next;
    }
    return ptr->val;
}

int find(LinkedList* list, int value){
    ListNode* ptr = list->head;
    for(int i=0; i<list->size; i++){
        if(ptr->val == value){
            return i;
        }
        ptr = ptr->next;
    }
    return -1;
}
int is_empty(LinkedList* list){
    return list->size == 0;
}
int size(LinkedList* list){
    return list->size;
}
void set_at(LinkedList* list, int index, int new_value){
    if(!index_validation(list, index)){
        return;
    }
    // find list[index]
    ListNode* ptr = list->head;
    for(int i=0; i<index; i++){
        ptr = ptr->next;
    }
    ptr->val = new_value;
}
#pragma endregion

#pragma region Other
void print_list(LinkedList* list){
    ListNode* ptr = list->head;
    printf("[");
    for(int i=0; i<list->size; i++){
        printf("%d", ptr->val);
        if(i!=list->size-1){
            printf(" ");
        }
        ptr = ptr->next;
    }
    printf("]\n");
}
void reverse(LinkedList* list){
    // corner case - size == 0
    if(list->size == 0){
        return;
    }
    // list[0] shall point NULL
    // head shall point list[size-1] 
    // list[n] shall point list[n-1]

    // always save pre/next node to prevent miss address
    // ptr->next = ptrPre
    // ptrNext->next = ptr (will perform during next loop)
    // since n node needs n steps to change the next
    ListNode* ptrPre = NULL;
    ListNode* ptr = list->head;
    ListNode* ptrNext = ptr->next;

    for(int i=0; i<list->size; i++){
        ptr->next = ptrPre;

        if(ptrNext == NULL){
            break;
        }
        ptrPre = ptr;
        ptr = ptrNext;
        ptrNext = ptrNext->next;
    }

    list->head = ptr;
}
LinkedList* clone_list(const LinkedList* list){
    LinkedList* output = create_list();
    output->size = list->size;  // NOTE: Size shall also be copied!!!
    ListNode* ptr_input = list->head;
    ListNode* ptr_output;
    ListNode* newData;
    for(int i=0; i<list->size; i++){
        newData = (ListNode*)malloc(sizeof(ListNode));
        newData->val = ptr_input->val;
        newData->next = NULL;
        if(output->head == NULL){
            output->head = newData;
            ptr_output = newData;
        }
        else{
            ptr_output->next = newData;
            ptr_output = ptr_output->next;
        }

        ptr_input = ptr_input->next;
    }
    return output;
}
#pragma endregion


int main(){
    
    printf("create_list\n");
    LinkedList* input = create_list();
    print_list(input);  // []

    printf("free_list\n");
    free_list(input);
    print_list(input);  // []

    printf("push\n");
    push_front(input, 2);
    push_front(input, 1);
    push_back(input, 3);
    print_list(input);  // [1, 2, 3]

    printf("insert_at\n");
    insert_at(input, 1, 9);
    print_list(input);  // [1, 9, 2, 3]

    printf("pop\n");
    pop_front(input);
    print_list(input);  // [9, 2, 3]
    pop_back(input);
    print_list(input);  // [9, 2]

    printf("delete\n");
    push_front(input, 3);
    push_front(input, 2);
    push_front(input, 1); // [1 ,2 ,3, 9, 2]
    delete_at(input, 4);
    print_list(input);  // [1 ,2 ,3, 9]

    printf("reverse\n");
    reverse(input);
    print_list(input);  // [9, 3, 2, 1]

    printf("clone\n");
    LinkedList* output = clone_list(input);
    print_list(output);  // [9, 3, 2, 1]

    printf("set\n");
    set_at(output, 0, 4);
    print_list(output);  // [4, 3, 2, 1]
    print_list(input);   // [9, 3, 2, 1]

    printf("get\n");
    printf("%d\n", find(input, 3));    //1
    printf("%d\n", get_at(input, 1));  //3

    printf("pop\n");
    pop_front(output);
    pop_front(output);
    pop_front(output);
    pop_front(output);
    print_list(output); // []
    print_list(input);  // [9, 3, 2, 1]
    pop_front(output);  // Error Message

    free_list(input);
    free_list(output);
    return 0;
}