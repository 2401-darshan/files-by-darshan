#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *lptr;
    struct node *rptr;
};

struct node *prev = NULL, *next = NULL;

void insertAtFirst(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = prev;

    if (prev == NULL) { 
        prev = next = newNode;
    } else {
        prev->lptr = newNode;
        prev = newNode;
    }
    printf("Inserted %d at the beginning.\n", x);
}

void insertAtLast(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = NULL;

    if (next == NULL) {
        prev = next = newNode;
    } else {
        next->rptr = newNode;
        newNode->lptr = next;
        next = newNode;
    }
    printf("Inserted %d at the end.\n", x);
}

void deleteAtOrd(int pos) {
    if (prev == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct node *save = prev;
    int i = 1;

    while (i < pos && save != NULL) {
        save = save->rptr;
        i++;
    }
    if (save == NULL) {
        printf("Invalid position.\n");
        return;
    }

    printf("Deleted element = %d\n", save->info);

    if (prev == next && save == prev) {
        prev = next = NULL;
    }
    else if (save == prev) {
        prev = prev->rptr;
        if (prev) prev->lptr = NULL;
    }
    else if (save == next) {
        next = next->lptr;
        if (next) next->rptr = NULL;
    }
    else {
        save->lptr->rptr = save->rptr;
        save->rptr->lptr = save->lptr;
    }
    free(save);
}


void display() {
    if (prev == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node *save = prev;
    printf("List: ");
    while (save != NULL) {
        printf("%d <-> ", save->info);
        save = save->rptr;
    }
    printf("NULL\n");
}

void main() {
    int choice, pos, n;

    while (1) {
        printf("\n------- DOUBLY LINKED LIST MENU ----------\n");
        printf("1. Insert at First\n");
        printf("2. Insert at Last\n");
        printf("3. Delete at Specific Position\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &n);
                insertAtFirst(n);
                break;
            case 2:
                printf("Enter value to insert at last: ");
                scanf("%d", &n);
                insertAtLast(n);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtOrd(pos);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

