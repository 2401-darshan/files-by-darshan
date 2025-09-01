#include <stdio.h>
#include <stdlib.h>

// Structure for a tree node
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to search for an element in postorder array
int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Function to construct binary tree from preorder and postorder
Node* constructTree(int preorder[], int postorder[], int* preIndex, 
                   int postStart, int postEnd, int size) {
    // Base case
    if (*preIndex >= size || postStart > postEnd)
        return NULL;

    // Create root node from preorder
    Node* root = createNode(preorder[*preIndex]);
    (*preIndex)++;

    // If this is a leaf node
    if (postStart == postEnd)
        return root;

    // Find the next element in preorder in postorder
    int nextInPreorder = preorder[*preIndex];
    int postIndex = search(postorder, postStart, postEnd, nextInPreorder);

    // Construct left and right subtrees
    if (postIndex != -1) {
        // Elements from postStart to postIndex form left subtree
        root->left = constructTree(preorder, postorder, preIndex, 
                                   postStart, postIndex, size);
        
        // Elements from postIndex+1 to postEnd-1 form right subtree
        root->right = constructTree(preorder, postorder, preIndex, 
                                    postIndex + 1, postEnd - 1, size);
    }

    return root;
}

// Function to print inorder traversal (for verification)
void printInorder(Node* root) {
    if (root == NULL)
        return;
    
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Function to print preorder traversal
void printPreorder(Node* root) {
    if (root == NULL)
        return;
    
    printf("%d ", root->data);
    printPreorder(root->left);
    printPreorder(root->right);
}

// Function to print postorder traversal
void printPostorder(Node* root) {
    if (root == NULL)
        return;
    
    printPostorder(root->left);
    printPostorder(root->right);
    printf("%d ", root->data);
}

// Function to free the tree
void freeTree(Node* root) {
    if (root == NULL)
        return;
    
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Function to get array input from user
void getArrayInput(int arr[], int size, const char* name) {
    printf("Enter %d elements for %s traversal: ", size, name);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

int main() {
    int size;
    
    printf("Binary Tree Construction from Preorder and Postorder Traversals\n");
    printf("============================================================\n\n");
    
    printf("Enter the number of nodes: ");
    scanf("%d", &size);
    
    if (size <= 0) {
        printf("Invalid size! Please enter a positive integer.\n");
        return 1;
    }
    
    int preorder[size];
    int postorder[size];
    
    printf("\n");
    getArrayInput(preorder, size, "preorder");
    getArrayInput(postorder, size, "postorder");
    
    // Validate that both arrays have the same elements
    int count[1000] = {0}; // Assuming elements are in range 0-999
    
    for (int i = 0; i < size; i++) {
        count[preorder[i]]++;
    }
    
    int valid = 1;
    for (int i = 0; i < size; i++) {
        count[postorder[i]]--;
    }
    
    for (int i = 0; i < 1000; i++) {
        if (count[i] != 0) {
            valid = 0;
            break;
        }
    }
    
    if (!valid) {
        printf("\nError: Preorder and Postorder arrays must contain the same elements!\n");
        return 1;
    }
    
    // Construct the tree
    int preIndex = 0;
    Node* root = constructTree(preorder, postorder, &preIndex, 0, size - 1, size);
    
    if (root == NULL) {
        printf("\nError: Could not construct tree from given traversals!\n");
        return 1;
    }
    
    printf("\nTree constructed successfully!\n\n");
    
    printf("Inorder traversal:   ");
    printInorder(root);
    printf("\n");
    
    printf("Preorder traversal:  ");
    printPreorder(root);
    printf("\n");
    
    printf("Postorder traversal: ");
    printPostorder(root);
    printf("\n");
    
    // Free allocated memory
    freeTree(root);
    
    return 0;
}
