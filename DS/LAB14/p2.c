#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* link;
};

void insertEnd(struct Node **first, int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->link = NULL;
    
    if (*first == NULL) {
        *first = newNode;
        newNode->link = *first;
        return;
    }

    struct Node* save = *first;
    while (save->link != *first)
        save = save->link;

    save->link = newNode;
    newNode->link = *first;
}

void splitList(struct Node *first, struct Node **first1, struct Node **first2) {
    if (first == NULL || first->link == first) {
        *first1 = first;
        *first2 = NULL;
        return;
    }

    struct Node* slow = first;
    struct Node* fast = first;

    while (fast->link != first && fast->link->link != first) {
        slow = slow->link;
        fast = fast->link->link;
    }

    if (fast->link->link == first)
        fast = fast->link;

    *first1 = first;
    *first2 = slow->link;

    slow->link = *first1;

    fast->link = *first2;
}

void printList(struct Node *first) {
    if (first == NULL) return;

    struct Node *save = first;
    do {
        printf("%d ", save->info);
        save = save->link;
    } while (save != first);
    printf("\n");
}

void main() {
    struct Node* first = NULL;
    struct Node* first1 = NULL;
    struct Node* first2 = NULL;

    insertEnd(&first, 1);
    insertEnd(&first, 2);
    insertEnd(&first, 3);
    insertEnd(&first, 4);
    insertEnd(&first, 5);
    insertEnd(&first, 6);

    printf("Original Circular Linked List:\n");
    printList(first);

    splitList(first, &first1, &first2);

    printf("\nFirst Half:\n");
    printList(first1);

    printf("\nSecond Half:\n");
    printList(first2);
}

