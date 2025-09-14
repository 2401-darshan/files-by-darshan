//simple queue implementation in C

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Enqueue function
void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        printf("Queue Overflow! Cannot insert %d\n", value);
    }
    else
    {
        if (front == -1)
            front = 0; // first element
        rear++;
        queue[rear] = value;
        printf("%d enqueued\n", value);
    }
}

// Dequeue function
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow! No element to dequeue\n");
    }
    else
    {
        printf("%d dequeued\n", queue[front]);
        front++;
    }
}

// Display function
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Simple Queue Menu ---\n");
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
