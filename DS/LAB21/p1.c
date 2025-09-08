#include<stdio.h>
int main()
{
    int n, key, found=0;
    printf("Enter size of array: ");
    scanf("%d",&n);

    int arr[n];

    for(int i=0; i<n; i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&arr[i]);
    }

    printf("Enter key to search: ");
    scanf("%d",&key);

    for(int i=0; i<n; i++)
    {
        if(arr[i] == key)
        {
            printf("Element found at index %d\n",i);
            found = 1;
            return 0;
        }
    }

    if(found == 1) {
        printf("Element founded...\n");
    } else {
        printf("Element not found...\n");
    }
    return 0;
}