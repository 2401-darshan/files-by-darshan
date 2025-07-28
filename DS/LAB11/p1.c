//IMPLEMENTATION OF STACK IN SINGLY LINKED LINEAR LIST

#include<stdio.h>
#include<stdlib.h>

struct node {
	int info;
	struct node *link;
};
struct node *first = NULL;

void push(int x) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->info = x;
	newNode->link = first;
	first = newNode;
}

void pop() {
	if(first==NULL) {
		return;
	}
	else {
		struct node *save = first;
		first = first->link;
		free(save);
	}
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
	push(4);
	push(3);
	push(2);
	push(1);
	pop(1);
	display();
}
