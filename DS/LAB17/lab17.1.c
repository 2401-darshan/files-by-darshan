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
bool same(struct Node *root1,struct Node *root2){
	if(root1==NULL&& root2==NULL){
		return true;
	}
	if(root1==NULL||root2==NULL){
		return false;
	}
	if(root1->data!=root2->data){
		return false;
	}
	return same(root1->left,root2->left)&&same(root1->right,root2->right);
}
void main()
{
	struct Node *root1=createNode(3);
	root1->left=createNode(2);
	root1->right=createNode(4);
	root1->left->right=createNode(1);
	
	struct Node *root2=createNode(3);
	root2->left=createNode(2);
	root2->right=createNode(4);
	root2->left->right=createNode(1);
	
	if(same(root1,root2)==true){
		printf("Given tree are same.");
		
	}
	else
	{
		printf("Given tree are not same.");
	}
}
