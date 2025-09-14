// Queue implementation using linked list in C

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue element
void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory not allocated!\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    { // empty queue
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued\n", value);
}

// Dequeue element
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node *temp = front;
    printf("%d dequeued\n", front->data);
    front = front->next;

    if (front == NULL)
        rear = NULL; // queue becomes empty
    free(temp);
}

// Display queue
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    struct Node *temp = front;
    printf("Queue elements: ");
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
        printf("\n--- Queue (Linked List) ---\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}
