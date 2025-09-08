#include <stdio.h>
void binarySearchIterative(int arr[], int n, int key)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            printf("Element found at index %d\n", mid);
            return;
        } 
        if (arr[mid] < key) {
            left = mid + 1;
        } 
        else {
            right = mid - 1;
        }
    }
    printf("Element not found...\n");
}
void binarySearchRecursive(int arr[], int left, int right, int key)
{
    if (left > right)
    {
        printf("Element not found...\n");
        return;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == key)
    {
        printf("Element found at index %d\n", mid);
        return;
    }
    if (arr[mid] < key)
    {
        binarySearchRecursive(arr, mid + 1, right, key);
    }
    else
    {
        binarySearchRecursive(arr, left, mid - 1, key);
    }
}
int main()
{
    int n, key;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d", &key);

    binarySearchIterative(arr, n, key);

    return 0;
}