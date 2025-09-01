#include<stdio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node* lptr;
	struct node* rptr;	
};
struct node *first=NULL;
struct node *last=NULL;

void insertAtFirst(int x)
{
	struct node *newNode=(struct node *)malloc (sizeof(struct node));
	newNode->info=x;
	if(first==NULL)
	{
		first=newNode;
		last=newNode;
		newNode->lptr=NULL;
		newNode->rptr=NULL;
	}
	else
	{
		newNode->rptr=first;
		first->lptr=newNode;
		first=newNode;
	}	
}
void deleteAlter()
{
	struct node* save = first;

	if(first==NULL || first->rptr==NULL)
	{
		return;
	}
	int count=1;
	while(save->rptr!=NULL)
	{
		if(count%2==0)
		{
			save->lptr->rptr=save->rptr;
			save->rptr->lptr=save->lptr;
		}
		save=save->rptr;
		count++;
	}
}
void display()
{
	struct node *save=first;
	while(save!=NULL)
	{
		printf("%d->",save->info);
		save=save->rptr;
	}
	printf("NULL\n");
	
}
void main()
{	
	insertAtFirst(11);
	insertAtFirst(12);
	insertAtFirst(13);
	insertAtFirst(14);
	insertAtFirst(15);
	display();
	deleteAlter();
	display();
}