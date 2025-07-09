#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};
struct node *first=NULL;
struct node *last=NULL;

void insertAtFirst(int x){
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	newNode->info=x;
	if(first==NULL){
		newNode->link=newNode;
		first=newNode;
		last=newNode;
	}
	else{
		newNode->link=first;
		last->link=newNode;
		first=newNode;
	}
}
void insertAtLast(int x){
	struct node *newNode=(struct node *)malloc(sizeof(struct node));
	newNode->info=x;
	if(first==NULL){
		newNode->link=first;
		first=newNode;
		last=newNode;
	}
	else{
		newNode->link=first;
		last->link=newNode;
		last=newNode;
		
		
	}
}
void deleteAtSpecifiedPosition(int x){
	int count=0;
	struct node *prev=NULL;
	struct node *curr=first;
	
	
	while(count!=x){
		prev=curr;
		curr=curr->link;
		count++;
	}
	prev->link=curr->link;
	if(curr == last){
		last = prev;
	}
	free(curr);
	
}
void display(){
	if(first==NULL){
		printf("----------linked list is empty-----------");
	}
	else{
		struct node *save=first;
		do{
			printf("%d->",save->info);
			save=save->link;
	 } while(save!=first);
		printf("NULL\n");
	}
}
void main(){
	int choice, n;
	while(1) {
		printf("\nenter 1 to insert at first\n");
		printf("enter 2 to insert at last\n");
		printf("enter 3 to delete node at specific\n");
		printf("enter 4 to display all nodes\n");
		printf("enter 5 to exit\n");
		printf("\n");
		printf("enter your choice : ");
		scanf("%d",&choice);
		
		if(choice==1) {
			printf("\n");
			int n;
			printf("Enter n to add node at first :");
			scanf("%d",&n);
			insertAtFirst(n);
		}
		else if(choice==2) {
			int n;
			printf("Enter n to insert node at last :");
			scanf("%d",&n);
			insertAtLast(n);
		}
		else if(choice==3) {
			printf("\n");
			printf("Enter position :");
			scanf("%d",&n);
			deleteAtSpecifiedPosition(n);
		}
		else if(choice==4) {
			printf("\n");
			display();
			printf("\n");
		}
		else if(choice==5) {
			break;
		}
	}
}
