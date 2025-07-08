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
void insertAtLast(int x)
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	struct node *save = first;
	newNode->info=x;
	newNode->link=NULL;
	
	if(first==NULL) {
		first = newNode;
	}
	else {
		while(save->link !=NULL) {
			save = save->link;
		}
		save->link=newNode;
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
void insertAtOrder(int x){
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	newNode->info=x;
	
//	struct node *pre=first;
	if(newNode->info<=first->info || first==NULL){
		newNode->link=first;
		first=newNode;
		return;
	}
	else{
		struct node *save=first;
		
		while(save->link!=NULL && newNode->info>=save->link->info){
	
			save=save->link;
		}
		newNode->link=save->link;
		save->link=newNode;
	}
	
}
void main()
{
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	
	int n;
	insertAtFirst(10);
	insertAtOrder(15);
	insertAtOrder(5);
	display();
}
