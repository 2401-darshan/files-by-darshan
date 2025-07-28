#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};

struct node* first = NULL;
void insertAtFirst(int x)
{
 struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->info=x;
	newNode->link=first;
	first=newNode;
	return;
}
void display()
{

	struct node* save=first;
	while(save!=NULL)
	{
		printf("%d ->",save->info);
		save=save->link;
	}
	printf("NULL\n");

}
void sort()
{
	struct node* current=first;
	struct node* next=current->link; 
	
	int opr;
	opr=1;
	while(opr)
	{
		current=first;
		next=current->link;
		opr=0;
		while(next!=NULL)
		{
			int temp;
			if(current->info>next->info)
			{
				temp=current->info;
				current->info=next->info;
				next->info=temp;
				opr=1;
			}
			current=current->link;
			next=next->link;	
		}	
	}	
}
void main()
{
	insertAtFirst(3);
	insertAtFirst(10);
	insertAtFirst(6);
	insertAtFirst(18);
	display();
	sort();
	display();
		
}
