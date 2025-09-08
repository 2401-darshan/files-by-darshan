// Write a program to implement Selection Sort using Array. 

#include<stdio.h>
int main()
{
    int arr[100], n, i, j, temp;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
    {
        printf("Enter element %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sorted array is:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}