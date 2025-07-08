#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(struct Node** head_ref, int data) {
    struct Node* new_node = createNode(data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    struct Node* temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_node;
}

// Function to print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to copy the linked list
struct Node* copyList(struct Node* head) {
    if (head == NULL)
        return NULL;

    struct Node* newHead = NULL;
    struct Node* tail = NULL;

    while (head != NULL) {
        struct Node* newNode = createNode(head->data);
        if (newHead == NULL) {
            newHead = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        head = head->next;
    }

    return newHead;
}

void main() {
    struct Node* original = NULL;

    append(&original, 1);
    append(&original, 2);
    append(&original, 3);

    printf("Original Linked List:\n");
    printList(original);

    struct Node* copied = copyList(original);

    printf("Copied Linked List:\n");
    printList(copied);
}
