// Improved by GPT-4.1

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// Node structure
typedef struct ListNode {
    int value;
    struct ListNode* next;
} ListNode;

// Linked list structure
typedef struct LinkedList {
    ListNode* head;
    int size;
} LinkedList;

// Index Validation for get/set/delete (0 <= index < size)
bool is_valid_index(const LinkedList* linked_list, int index) {
    if (linked_list == NULL) {
        printf("LinkedList pointer is NULL.\n");
        return false;
    }
    if (index < 0 || index >= linked_list->size) {
        printf("Index %d out of range.\n", index);
        return false;
    }
    return true;
}

// Index Validation for insert (0 <= index <= size)
bool is_valid_insert_index(const LinkedList* linked_list, int index) {
    if (linked_list == NULL) {
        printf("LinkedList pointer is NULL.\n");
        return false;
    }
    if (index < 0 || index > linked_list->size) {
        printf("Insert index %d out of range.\n", index);
        return false;
    }
    return true;
}

// Create & Delete
LinkedList* create_linked_list() {
    LinkedList* new_linked_list = (LinkedList*)malloc(sizeof(LinkedList));
    if (new_linked_list == NULL) {
        printf("Memory allocation failed for LinkedList.\n");
        exit(EXIT_FAILURE);
    }
    new_linked_list->head = NULL;
    new_linked_list->size = 0;
    return new_linked_list;
}

void free_linked_list(LinkedList* linked_list) {
    if (linked_list == NULL) {
        return;
    }
    ListNode* current_node = linked_list->head;
    while (current_node != NULL) {
        ListNode* next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
    linked_list->head = NULL;
    linked_list->size = 0;
}

// Add Node
void push_front(LinkedList* linked_list, int value) {
    if (linked_list == NULL) {
        printf("LinkedList pointer is NULL.\n");
        return;
    }
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    if (new_node == NULL) {
        printf("Memory allocation failed for ListNode.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = linked_list->head;
    linked_list->head = new_node;
    linked_list->size++;
}

void push_back(LinkedList* linked_list, int value) {
    if (linked_list == NULL) {
        printf("LinkedList pointer is NULL.\n");
        return;
    }
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    if (new_node == NULL) {
        printf("Memory allocation failed for ListNode.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = NULL;

    if (linked_list->head == NULL) {
        linked_list->head = new_node;
    } else {
        ListNode* current_node = linked_list->head;
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }
    linked_list->size++;
}

void insert_at(LinkedList* linked_list, int index, int value) {
    if (!is_valid_insert_index(linked_list, index)) {
        return;
    }
    if (index == 0) {
        push_front(linked_list, value);
        return;
    }
    ListNode* previous_node = linked_list->head;
    for (int i = 0; i < index - 1; i++) {
        previous_node = previous_node->next;
    }
    ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
    if (new_node == NULL) {
        printf("Memory allocation failed for ListNode.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = previous_node->next;
    previous_node->next = new_node;
    linked_list->size++;
}

// Remove Node
void pop_front(LinkedList* linked_list) {
    if (linked_list == NULL) {
        printf("LinkedList pointer is NULL.\n");
        return;
    }
    if (linked_list->size <= 0) {
        printf("Cannot pop_front from empty list. No action performed.\n");
        return;
    }
    ListNode* node_to_free = linked_list->head;
    linked_list->head = linked_list->head->next;
    linked_list->size--;
    free(node_to_free);
}

void pop_back(LinkedList* linked_list) {
    if (linked_list == NULL) {
        printf("LinkedList pointer is NULL.\n");
        return;
    }
    if (linked_list->size <= 0) {
        printf("Cannot pop_back from empty list. No action performed.\n");
        return;
    }
    if (linked_list->size == 1) {
        free(linked_list->head);
        linked_list->head = NULL;
        linked_list->size = 0;
        return;
    }
    ListNode* current_node = linked_list->head;
    while (current_node->next->next != NULL) {
        current_node = current_node->next;
    }
    free(current_node->next);
    current_node->next = NULL;
    linked_list->size--;
}

void delete_at(LinkedList* linked_list, int index) {
    if (!is_valid_index(linked_list, index)) {
        return;
    }
    if (index == 0) {
        pop_front(linked_list);
        return;
    }
    ListNode* previous_node = linked_list->head;
    for (int i = 0; i < index - 1; i++) {
        previous_node = previous_node->next;
    }
    ListNode* node_to_delete = previous_node->next;
    previous_node->next = node_to_delete->next;
    free(node_to_delete);
    linked_list->size--;
}

// Get & Set
int get_at(const LinkedList* linked_list, int index) {
    if (!is_valid_index(linked_list, index)) {
        return -1;
    }
    ListNode* current_node = linked_list->head;
    for (int i = 0; i < index; i++) {
        current_node = current_node->next;
    }
    return current_node->value;
}

int find(const LinkedList* linked_list, int value) {
    if (linked_list == NULL) {
        return -1;
    }
    ListNode* current_node = linked_list->head;
    int index = 0;
    while (current_node != NULL) {
        if (current_node->value == value) {
            return index;
        }
        current_node = current_node->next;
        index++;
    }
    return -1;
}

bool is_empty(const LinkedList* linked_list) {
    if (linked_list == NULL) {
        return true;
    }
    return linked_list->size == 0;
}

int get_size(const LinkedList* linked_list) {
    if (linked_list == NULL) {
        return 0;
    }
    return linked_list->size;
}

void set_at(LinkedList* linked_list, int index, int new_value) {
    if (!is_valid_index(linked_list, index)) {
        return;
    }
    ListNode* current_node = linked_list->head;
    for (int i = 0; i < index; i++) {
        current_node = current_node->next;
    }
    current_node->value = new_value;
}

// Other
void print_linked_list(const LinkedList* linked_list) {
    if (linked_list == NULL) {
        printf("[]\n");
        return;
    }
    ListNode* current_node = linked_list->head;
    printf("[");
    for (int i = 0; i < linked_list->size; i++) {
        printf("%d", current_node->value);
        if (i != linked_list->size - 1) {
            printf(", ");
        }
        current_node = current_node->next;
    }
    printf("]\n");
}

void reverse_linked_list(LinkedList* linked_list) {
    if (linked_list == NULL || linked_list->size <= 1) {
        return;
    }
    ListNode* previous_node = NULL;
    ListNode* current_node = linked_list->head;
    while (current_node != NULL) {
        ListNode* next_node = current_node->next;
        current_node->next = previous_node;
        previous_node = current_node;
        current_node = next_node;
    }
    linked_list->head = previous_node;
}

LinkedList* clone_linked_list(const LinkedList* linked_list) {
    if (linked_list == NULL) {
        return NULL;
    }
    LinkedList* cloned_list = create_linked_list();
    ListNode* current_node = linked_list->head;
    ListNode** tail = &(cloned_list->head);
    while (current_node != NULL) {
        ListNode* new_node = (ListNode*)malloc(sizeof(ListNode));
        if (new_node == NULL) {
            printf("Memory allocation failed for ListNode.\n");
            exit(EXIT_FAILURE);
        }
        new_node->value = current_node->value;
        new_node->next = NULL;
        *tail = new_node;
        tail = &(new_node->next);
        current_node = current_node->next;
        cloned_list->size++;
    }
    return cloned_list;
}

// Main for Testing
int main() {
    printf("create_linked_list\n");
    LinkedList* input_list = create_linked_list();
    print_linked_list(input_list);

    printf("push\n");
    push_front(input_list, 2);
    push_front(input_list, 1);
    push_back(input_list, 3);
    print_linked_list(input_list);  // [1, 2, 3]

    printf("insert_at\n");
    insert_at(input_list, 1, 9);
    print_linked_list(input_list);  // [1, 9, 2, 3]

    printf("pop\n");
    pop_front(input_list);
    print_linked_list(input_list);  // [9, 2, 3]
    pop_back(input_list);
    print_linked_list(input_list);  // [9, 2]

    printf("delete\n");
    push_front(input_list, 3);
    push_front(input_list, 2);
    push_front(input_list, 1); // [1, 2, 3, 9, 2]
    delete_at(input_list, 4);
    print_linked_list(input_list);  // [1, 2, 3, 9]

    printf("reverse\n");
    reverse_linked_list(input_list);
    print_linked_list(input_list);  // [9, 3, 2, 1]

    printf("clone\n");
    LinkedList* output_list = clone_linked_list(input_list);
    print_linked_list(output_list);  // [9, 3, 2, 1]

    printf("set\n");
    set_at(output_list, 0, 4);
    print_linked_list(output_list);  // [4, 3, 2, 1]
    print_linked_list(input_list);   // [9, 3, 2, 1]

    printf("get\n");
    printf("%d\n", find(input_list, 3));    // 1
    printf("%d\n", get_at(input_list, 1));  // 3

    printf("pop\n");
    pop_front(output_list);
    pop_front(output_list);
    pop_front(output_list);
    pop_front(output_list);
    print_linked_list(output_list); // []
    print_linked_list(input_list);  // [9, 3, 2, 1]
    pop_front(output_list);  // Error Message

    free_linked_list(input_list);
    free_linked_list(output_list);
    return 0;
}