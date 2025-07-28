//IMPLEMENTATION OF QUEUE IN SINGLY LINKED LINEAR LIST

#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node *link;
};
struct node *first = NULL;

void insertAtFirst(int x)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = x;
	newNode->link = first;
	first = newNode;
}

void deleteAtLast() {
    if (first == NULL) return;

    if (first->link == NULL) {
        free(first);
        first = NULL;
        return;
    }

    struct node *save = first;
    while (save->link->link != NULL) {
        save = save->link;
    }
    free(save->link);
    save->link = NULL;
}

void display() {
	struct node *save = first;
	while(save != NULL) {
		printf("%d->",save->info);
		save=save->link;
	}
	printf("NULL\n");
}

void main()
{
	insertAtFirst(500);
	insertAtFirst(400);
	insertAtFirst(300);
	insertAtFirst(200);
	insertAtFirst(100);
	
	deleteAtLast();
	display();
}
