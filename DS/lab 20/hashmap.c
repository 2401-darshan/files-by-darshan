#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define EMPTY -1 
#define DELETED -2

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

int hashFunction(int key) {
    return key % SIZE;
}

void add(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (hashTable[newIndex] == EMPTY || hashTable[newIndex] == DELETED) {
            hashTable[newIndex] = key;
            printf("Inserted %d at index %d\n", key, newIndex);
            return;
        } else if (hashTable[newIndex] == key) {
            printf("Key %d already exists\n", key);
            return;
        }
    }
    printf("Hash table is full, cannot insert %d\n", key);
}

void removeKey(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (hashTable[newIndex] == EMPTY) {
            printf("Key %d not found\n", key);
            return;
        } else if (hashTable[newIndex] == key) {
            hashTable[newIndex] = DELETED;
            printf("Key %d removed\n", key);
            return;
        }
    }
    printf("Key %d not found\n", key);
}

int contains(int key) {
    int index = hashFunction(key);

    for (int i = 0; i < SIZE; i++) {
        int newIndex = (index + i) % SIZE;

        if (hashTable[newIndex] == EMPTY) {
            return 0; // not found
        } else if (hashTable[newIndex] == key) {
            return 1; // found
        }
    }
    return 0;
}

void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("[%d] : EMPTY\n", i);
        else if (hashTable[i] == DELETED)
            printf("[%d] : DELETED\n", i);
        else
            printf("[%d] : %d\n", i, hashTable[i]);
    }
}

int main() {
    init();
    int choice, key;

    while (1) {
        printf("\n--- HashMap Menu ---\n");
        printf("1. Add\n");
        printf("2. Remove\n");
        printf("3. Contains\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to add: ");
                scanf("%d", &key);
                add(key);
                break;
            case 2:
                printf("Enter key to remove: ");
                scanf("%d", &key);
                removeKey(key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (contains(key))
                    printf("Key %d found\n", key);
                else
                    printf("Key %d not found\n", key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}