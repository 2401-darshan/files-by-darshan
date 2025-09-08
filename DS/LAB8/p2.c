#include <stdio.h>
#include <stdlib.h>
#define n 5

int queue[n];
int front = -1, rear = -1, i;

void insert(int value)
{
	if ((front == 0 && rear == n - 1) || (rear + 1) % n == front)
	{
		printf("\nQUEUE OVERFLOW...\n");
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
			rear = (rear + 1) % n;
		}
		queue[rear] = value;
		printf("\nInserted %d into circular queue\n", value);
	}
}

void delete()
{
	if (front == -1)
	{
		printf("\nQUEUE UNDERFLOW...\n");
	}
	else
	{
		printf("\nDeleted %d from circular queue\n", queue[front]);
		if (front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = (front + 1) % n;
		}
	}
}

void display()
{
	if (front == -1)
	{
		printf("\nQUEUE UNDERFLOW\n");
	}
	else
	{
		printf("\nQueue elements are : ");
		int i = front;
		while (1)
		{
			printf("%d", queue[i]);
			if (i == rear)
			{
				break;
			}
			i = (i + 1) % n;
		}
		printf("\n");
	}
}

int main()
{
	int choice, value;

	while (1)
	{
		printf("\n====== Circular Queue Menu ======\n");
		printf("1. INSERT\n");
		printf("2. DELETE\n");
		printf("3. DISPLAY\n");
		printf("4. EXIT\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("Enter value to insert: ");
			scanf("%d", &value);
			insert(value);
			break;

		case 2:
			delete();
			break;

		case 3:
			display();
			break;

		case 4:
			printf("Exiting program...\n");
			exit(0);

		default:
			printf("Invalid choice! Try again.\n");
		}
	}
	return 0;
}
