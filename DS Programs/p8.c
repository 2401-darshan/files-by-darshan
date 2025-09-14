// Hash Map implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10 // size of hash table

// Node structure
struct Node
{
    int key;
    int value;
    struct Node *next;
};

struct Node *hashTable[SIZE];

// Hash function
int hash(int key)
{
    return key % SIZE;
}

// Insert or Update key-value pair
void put(int key, int value)
{
    int index = hash(key);
    struct Node *temp = hashTable[index];

    // Update if key already exists
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            temp->value = value;
            printf("Key %d updated with value %d\n", key, value);
            return;
        }
        temp = temp->next;
    }

    // Create new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    printf("Key %d inserted with value %d\n", key, value);
}

// Get value by key
void get(int key)
{
    int index = hash(key);
    struct Node *temp = hashTable[index];
    while (temp != NULL)
    {
        if (temp->key == key)
        {
            printf("Key %d has value %d\n", key, temp->value);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d not found\n", key);
}

// Remove key-value pair
void removeKey(int key)
{
    int index = hash(key);
    struct Node *temp = hashTable[index];
    struct Node *prev = NULL;

    while (temp != NULL)
    {
        if (temp->key == key)
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
            printf("Key %d removed\n", key);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Key %d not found\n", key);
}

// Display all key-value pairs
void display()
{
    printf("\nHash Map contents:\n");
    for (int i = 0; i < SIZE; i++)
    {
        printf("[%d]: ", i);
        struct Node *temp = hashTable[i];
        while (temp != NULL)
        {
            printf("(%d -> %d) ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main menu
int main()
{
    int choice, key, value;

    while (1)
    {
        printf("\n--- Hash Map Menu ---\n");
        printf("1. Put (Insert/Update)\n");
        printf("2. Get (Search)\n");
        printf("3. Remove\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%d", &value);
            put(key, value);
            break;
        case 2:
            printf("Enter key to search: ");
            scanf("%d", &key);
            get(key);
            break;
        case 3:
            printf("Enter key to remove: ");
            scanf("%d", &key);
            removeKey(key);
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
