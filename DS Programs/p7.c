// Hash Set implementation in C 

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10 // size of hash table

// Node structure for chaining
struct Node
{
    int data;
    struct Node *next;
};

struct Node *hashTable[SIZE]; // array of linked lists

// Hash function
int hash(int key)
{
    return key % SIZE;
}

// Insert element into hash set
void insert(int value)
{
    int index = hash(value);

    // Check if already exists (avoid duplicates in set)
    struct Node *temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("%d already exists in set\n", value);
            return;
        }
        temp = temp->next;
    }

    // Create new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("%d inserted\n", value);
}

// Search element
int contains(int value)
{
    int index = hash(value);
    struct Node *temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->data == value)
            return 1;
        temp = temp->next;
    }
    return 0;
}

// Remove element
void removeElement(int value)
{
    int index = hash(value);
    struct Node *temp = hashTable[index];
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            if (prev == NULL)
            {
                hashTable[index] = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            free(temp);
            printf("%d removed from set\n", value);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("%d not found in set\n", value);
}

// Display hash set
void display()
{
    printf("\nHash Set contents:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("[%d]: ", i);
        struct Node *temp = hashTable[i];
        while (temp != NULL)
        {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// Main menu
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Hash Set Menu ---\n");
        printf("1. Insert\n");
        printf("2. Remove\n");
        printf("3. Contains\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            insert(value);
            break;
        case 2:
            printf("Enter value to remove: ");
            scanf("%d", &value);
            removeElement(value);
            break;
        case 3:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (contains(value))
                printf("%d found in set\n", value);
            else
                printf("%d not found in set\n", value);
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
