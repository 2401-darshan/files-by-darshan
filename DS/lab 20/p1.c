#include<stdio.h>

int n;
int hashset[100];

void init()
{
    for (int i = 0; i < n; i++)
    {
        hashset[i] = -1;
    }
}

int f(int key)
{
    return key % n;
}

void add(int key)
{
    int index = f(key);
    if (hashset[index] == -1)
    {
        hashset[index] = key;
        return;
    }
    if (hashset[index] == key)
    {
        printf("Key already exists\n");
        return;
    }
    // collision resolution by linear probing
    for (int probe = 1; probe < n; probe++)
    {
        int i = (index + probe) % n;
        if (hashset[i] == -1)
        {
            hashset[i] = key;
            return;
        }
        else if (hashset[i] == key)
        {
            printf("Key already exists\n");
            return;
        }
    }
    printf("Hashset is full\n");
}

int contains(int key)
{
    int index = f(key);
    for (int probe = 0; probe < n; probe++)
    {
        int i = (index + probe) % n;
        if (hashset[i] == -1)
        {
            return 0;
        }
        if (hashset[i] == key)
        {
            return 1;
        }
    }
    return 0;
}

void display()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", hashset[i]);
    }
    printf("\n");
}

int main()
{
    int key, count;
    printf("Enter size of hashset: ");
    scanf("%d", &n);
    init();
    printf("Enter number of elements to insert: ");
    scanf("%d", &count);
    
    for (int i = 0; i < count; i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        add(key);
    }
    display();
    printf("Enter key to search: ");
    scanf("%d", &key);
    if (contains(key)) {
        printf("Key found in hashset\n");
    }
    else {
        printf("Key not found in hashset\n");
    }
    return 0;
}
