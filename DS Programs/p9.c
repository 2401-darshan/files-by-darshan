// Search Algorithms in C: Linear Search, Binary Search (Iterative and Recursive)

#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i; // return index
        }
    }
    return -1;
}

// Binary Search (Iterative)
int binarySearchLoop(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Binary Search (Recursive)
int binarySearchRec(int arr[], int low, int high, int key)
{
    if (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            return binarySearchRec(arr, mid + 1, high, key);
        else
            return binarySearchRec(arr, low, mid - 1, key);
    }
    return -1;
}

// Main function
int main()
{
    int arr[20], n, key, choice, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements (sorted for binary search):\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    while (1)
    {
        printf("\n--- Search Menu ---\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search (Loop)\n");
        printf("3. Binary Search (Recursion)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            result = linearSearch(arr, n, key);
            if (result != -1)
                printf("Element found at index %d\n", result);
            else
                printf("Element not found\n");
            break;

        case 2:
            result = binarySearchLoop(arr, n, key);
            if (result != -1)
                printf("Element found at index %d\n", result);
            else
                printf("Element not found\n");
            break;

        case 3:
            result = binarySearchRec(arr, 0, n - 1, key);
            if (result != -1)
                printf("Element found at index %d\n", result);
            else
                printf("Element not found\n");
            break;

        case 4:
            return 0;

        default:
            printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
