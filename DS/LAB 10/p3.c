#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *link;
};

struct node* createnode(int info) {
    struct node* newNode = (struct node *) malloc(sizeof(struct node));
    newNode->info = info;
    newNode->link = NULL;
    return newNode;
}

// Function to insert a node at the end of the circular linked list
void insertEnd(struct node** first, int info) {
    struct node* newnode = createnode(info);

    if (*first == NULL) {
        *first = newnode;
        newnode->link = *first;  // Point to itself
        return;
    }

    struct node* save = *first;
    while (save->link != *first) {
        save = save->link;
    }
    save->link = newnode;
    newnode->link = *first;
}

// Function to count the number of nodes in the circular linked list
int countnodes(struct node* first) {
    if (first == NULL)
        return 0;

    int count = 1;
    struct node* save = first->link;

    while (save != first) {
        count++;
        save = save->link;
    }

    return count;
}

// Function to display the circular linked list
void displayList(struct node* first) {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* save = first;
    do {
        printf("%d -> ", save->info);
        save = save->link;
    } while (save != first);
    printf("(back to first)\n");
}

void main() {
    struct node* first = NULL;

    // Sample insertions
    insertEnd(&first, 10);
    insertEnd(&first, 20);
    insertEnd(&first, 30);
    insertEnd(&first, 40);

    printf("Circular Linked List:\n");
    displayList(first);

    int total = countnodes(first);
    printf("Total number of nodes: %d\n", total);
}

