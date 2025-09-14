// Singly Linked List implementation in C

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL; // start of linked list

// Insert at beginning
void insertFirst(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
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
    printf("%d deleted from beginning\n", head->data);
    head = head->next;
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
    if (head->next == NULL)
    {
        printf("%d deleted from end\n", head->data);
        free(head);
        head = NULL;
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    printf("%d deleted from end\n", temp->data);
    prev->next = NULL;
    free(temp);
}

// Delete specific node (by value)
void deleteNode(int value)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;

    // If first node is the one
    if (head->data == value)
    {
        head = head->next;
        printf("%d deleted from list\n", temp->data);
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("%d not found in list\n", value);
    }
    else
    {
        prev->next = temp->next;
        printf("%d deleted from list\n", temp->data);
        free(temp);
    }
}

// Reverse linked list
void reverseList()
{
    struct Node *prev = NULL, *curr = head, *next = NULL;

    while (curr != NULL)
    {
        next = curr->next; // store next
        curr->next = prev; // reverse link
        prev = curr;
        curr = next;
    }
    head = prev;
    printf("List reversed successfully\n");
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

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert from First\n");
        printf("2. Insert from Last\n");
        printf("3. Delete from First\n");
        printf("4. Delete from Last\n");
        printf("5. Delete Specific Node\n");
        printf("6. Reverse List\n");
        printf("7. Display\n");
        printf("8. Exit\n");
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
            printf("Enter value to delete: ");
            scanf("%d", &value);
            deleteNode(value);
            break;
        case 6:
            reverseList();
            break;
        case 7:
            display();
            break;
        case 8:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
