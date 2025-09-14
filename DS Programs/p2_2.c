// Circular Queue implementation in C

#include <stdio.h>
#define SIZE 5

int cqueue[SIZE];
int front = -1, rear = -1;

// Enqueue in circular queue
void enqueue(int value)
{
    if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front)
    {
        printf("Circular Queue Overflow! Cannot insert %d\n", value);
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % SIZE;
        }
        cqueue[rear] = value;
        printf("%d enqueued\n", value);
    }
}

// Dequeue in circular queue
void dequeue()
{
    if (front == -1)
    {
        printf("Circular Queue Underflow! No element to dequeue\n");
    }
    else
    {
        printf("%d dequeued\n", cqueue[front]);
        if (front == rear)
        { // last element deleted
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
    }
}

// Display elements of circular queue
void display()
{
    if (front == -1)
    {
        printf("Circular Queue is empty\n");
    }
    else
    {
        printf("Circular Queue elements: ");
        int i = front;
        while (1)
        {
            printf("%d ", cqueue[i]);
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        printf("\n");
    }
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Circular Queue Menu ---\n");
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
