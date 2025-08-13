#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct node
{
    int info;
    struct node *lptr;
    struct node *rptr;
};
struct node *root = NULL;
struct node *root1 = NULL;
struct node *newNode(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->info = x;
    newNode->lptr = NULL;
    newNode->rptr = NULL;
    return newNode;
}
struct node *insert(int x, struct node *root)
{
    if (root == NULL)
    {
        root = newNode(x);
        return root;
    }
    else
    {
        if (x < root->info)
        {
            root->lptr = insert(x, root->lptr);
        }
        else
        {
            root->rptr = insert(x, root->rptr);
        }
    }
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d,", root->info);
        preorder(root->lptr);
        preorder(root->rptr);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->lptr);
        printf("%d,", root->info);
        inorder(root->rptr);
    }
}

void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->lptr);
        postorder(root->rptr);
        printf("%d,", root->info);
    }
}
bool same(struct node *root, struct node *root1)
{
    if (root == NULL && root1 == NULL)
    {
        return true;
    }
    if (root == NULL || root1 == NULL)
    {
        return false;
    }
    return ((root->info == root1->info) && same(root->lptr, root1->lptr) && same(root->rptr, root1->rptr));
}

bool symm(struct node *rootl, struct node *rootr)
{
    if (rootl == NULL && rootr == NULL)
    {
        return true;
    }
    if (rootl == NULL || rootr == NULL)
    {
        return false;
    }
    return ((rootl->info == rootr->info) && same(rootl->lptr, rootr->rptr) && same(rootl->rptr, rootr->lptr));
}
bool isIden(struct node *root){
    if(root==NULL){
        return true;
    }
    return symm(root->lptr,root->rptr);
}
void main()
{
    root = newNode(8);
    root->lptr=newNode(5);
    root->rptr=newNode(5);
    root->lptr->lptr=newNode(3);
    root->lptr->rptr=newNode(6);
    root->rptr->lptr=newNode(6);
    root->rptr->rptr=newNode(5);
    // root = insert(5, root);
    // root = insert(5, root);
    // root = insert(3, root);
    // root = insert(6, root);
    // root = insert(6, root);
    // root = insert(3, root);
    // root1 = newNode(10);
    // root1 = insert(15, root1);
    // root1 = insert(20, root1);
    // root1 = insert(6, root1);
    if (isIden(root))
        printf("tree is sym");
    else
        printf("trees is not sym");
    
}