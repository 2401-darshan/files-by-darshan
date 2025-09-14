// Doubly Linked List implementation in C

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Insert at beginning
void insertFirst(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
    printf("%d inserted at beginning\n", value);
}

// Insert at end
void insertLast(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
    }
    else
    {
        struct Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("%d inserted at end\n", value);
}

// Delete from beginning
void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    printf("%d deleted from beginning\n", temp->data);

    head = head->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    free(temp);
}

// Delete from end
void deleteLast()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;

    if (temp->next == NULL)
    {
        printf("%d deleted from end\n", temp->data);
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    printf("%d deleted from end\n", temp->data);
    temp->prev->next = NULL;
    free(temp);
}

// Display list
void display()
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    printf("List elements: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main menu
int main()
{
    int choice, value;
    while (1)
    {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Insert from First\n");
        printf("2. Insert from Last\n");
        printf("3. Delete from First\n");
        printf("4. Delete from Last\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insertFirst(value);
            break;
        case 2:
            printf("Enter value: ");
            scanf("%d", &value);
            insertLast(value);
            break;
        case 3:
            deleteFirst();
            break;
        case 4:
            deleteLast();
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
