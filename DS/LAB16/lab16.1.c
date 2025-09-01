#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;
struct node *createNode(int value){
	struct node *newNode=(structnode*)malloc(sizeof(struct node*));
	newNode->data=value;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
struct node *insert (struct node* root,int value)
{
	if(root==NULL)
	{
		return createNode(value);
	}
	if(value<root->data)
	{
		root->left=insertNode(root->left,value);
	}
	if(value>root->data)
	{
		root->right=insertNode(root->right,value);
	}
	return root;
}
void preorderTraversal(struct node *root)
{
	if(root!=NULL)
	{
		printf("%d",root->data);
		preoderTraversal(root->left);
		preoderTraversal(root->right);
	}
}
void inorderTraversal(struct node *root)
{
	if(root!=NULL)
	{
			inoderTraversal(root->left);
			printf("%d",root->data);
			inoderTraversal(root->right);
	}
}
void postorderTraversal(struct node *root)
{
	if(root!=NULL)
	{
			postoderTraversal(root->left);
			postoderTraversal(root->right);
			printf("%d",root->data);
	}
}
void main()
{
	int choice,value;
	printf("Enter 1 for insertnode=");
	printf("Enter 2 for preordernode=");
	printf("Enter 3 for inordernode=");
	printf("Enter 4 for postordernode=");
	printf("Enter the Choice=");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: printf("Enter value to insert=");
				scanf("%d",&value);
				root=insertNode(root)
	}
	
}



