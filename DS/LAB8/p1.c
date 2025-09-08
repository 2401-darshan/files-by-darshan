#include<stdio.h>
#include<stdlib.h>
#define n 5

int queue[n];
int front = -1, rear = -1, i;

void enqueue(int value) {
    if(rear == n-1) {
        printf("QUEUE OVERFLOW.\n");
    }
    else{
        if(front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("\n Inserted %d into the queue.\n",value);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("\nQUEUE UNDERFLOW!\n");
    } else {
        printf("\nDeleted %d from the queue\n", queue[front]);
        front++;
    }
}

void display() {
    if(front == -1 || front > rear) {
        printf("\nQueue is EMPTY!\n");
    }
    else {
        printf("\nQUEUE elements are: ");
        for(i = front; i <= rear ; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void main()
{
    int choice, value;
	while(1) {
		printf("\n :------- QUEUE MENU ---------:\n");
    	printf("1. ENQUEUE\n");
    	printf("2. DEQUEUE\n");
    	printf("3. DISPLAY\n");
    	printf("4. EXIT\n");

    	printf("Enter your choice : ");
    	scanf("%d", &choice);
    
    	switch(choice)
    	{
        	case 1: printf("Enter element to insert : ");
            	    scanf("%d",&value);
            	    enqueue(value);
                	break;

        	case 2: dequeue();
            	    break;

        	case 3: display();
            	    break;

	        case 4: exit(0);
    	            break;

    	    default: printf("\nINVALID CHOICE\n");
    	}
	}
}
