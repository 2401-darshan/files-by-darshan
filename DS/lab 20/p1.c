#include <stdio.h>

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
    int idx = f(key);
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
            for (int probe = 0; probe < n; probe++)
            {
                int i = newIndex = (idx + probe) % n;
                if (hashset[newIndex] == -1)
                {
                    hashset[newIndex] = key;
                    return;
                }
                else if (hashset[newIndex] == key)
                {
                    printf("Key already exists\n");
                    return;
                }
            }
        }
    }
}