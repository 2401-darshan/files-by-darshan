#include <stdio.h>

void init() {
    for (int i = 0; i < n; i++)
    {
        hashset[i] = -1;
    }
}
int f(int key) {
    return key % n;
}

void add(int key) {
    int index = f(key);
    while (hashset[index] != -1)
    {
        if (hashset[index] == key)
        {
            hashset[index] = key;
            return;
        }
        else if (hashset[index] == key)
        {
            printf("Key already exists\n");
            return;
        }
        else
        {
            // collision
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
    }
}

void display() {
    for(int i = 0; i < n; i++) {
        printf("%d ", hashset[i]);
    }
    printf("\n");
}

int main() {
    int i, key, n, hashset[100];
    for(int i=0; i < n; i++) {
        printf("Enter key: ");
        scanf("%d", &key);
        add(key);
    }
    display();
    return 0;
}
