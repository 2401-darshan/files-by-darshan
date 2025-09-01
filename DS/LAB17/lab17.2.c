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
	return same(root1->right,root2->left)&&same(root1->left,root2->right);
}
bool symetric(struct Node*root1){
	if(root1==NULL){
		return 1;
	}
	else{
		return(same(root1->left,root1->right));
	}
}
void main()
{
	struct Node *root1=createNode(3);
	root1->left=createNode(5);
	root1->right=createNode(5);
	root1->left->left=createNode(5);
	
	
	root1->left->right=createNode(6);
	root1->right->left=createNode(6);
	root1->right->right=createNode(5);
	
	if(symetric(root1)==true){
		printf("Given Trees are symetric.");		
	}
	else
	{
		printf("Given tree are not symetric.");
	}BBB
}
