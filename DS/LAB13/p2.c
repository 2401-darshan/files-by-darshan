#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;han
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
int gcd(int a , int b)
{
	int min,i,gcd;
	
	if(a>b)
	{
		min=b;
	}
	else
	{
		min=a;
	}
	for(i=min;i>=1;i--)
	{
		if(a%i==0 && b%i==0)
		{
			gcd=i;
			break;
		}
	}
	return gcd;
}
void insertGcd()
{
	struct node* current=first;
	struct node*next=current->link;
	
	while(next!=NULL)
	{
	 struct node* newNode = (struct node*)malloc(sizeof(struct node));
	 newNode->info=gcd(current->info,next->info);
	 current->link=newNode;
	 newNode->link=next;
	 current=newNode->link;
	 next=next->link;
	 
	}
}
void main()
{
	insertAtFirst(3);
	insertAtFirst(10);
	insertAtFirst(6);
	insertAtFirst(18);
	display();
	insertGcd();
	display();
	
}
