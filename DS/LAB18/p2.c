#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
	int data;
	struct Node *left;
	struct Node *right;
};
struct Node* createNode(int val){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->data=val;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
int smallest(struct Node* root)
{
	if(root==NULL)
	{
		printf("Tree is empty.");
	}
	if(root->left==NULL)
	{
		return root->data;
	}
	return smallest(root->left);
}
int largest(struct Node* root)
{
	if(root==NULL)
	{
		printf("Tree is empty.");
	}
	if(root->left==NULL)
	{
		return root->data;
	}
	return smallest(root->right);
}
void main()
{
	struct Node *root=createNode(10);
	root->left=createNode(8);
	root->right=createNode(17);
	root->left->left=createNode(7); 
	root->left->left->left=createNode(5);
	root->left->right=createNode(9);
	root->right->left=createNode(15);
	root->right->right=createNode(18);
	
	
	printf("Smallest %d\n",smallest(root));
	printf("Largest %d",largest(root));
}
