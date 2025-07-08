#include<stdio.h>
void main()
{
	int n, i;
	printf("Enter n:");
	scanf("%d",&n);
	
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		printf("Enter array element arr[%d] : ",i);
		scanf("%d",&arr[i]);
	}
	
	for(i=0;i<n;i++)
	{
		printf("\nArray element arr[%d] is %d",i,arr[i]);
	}
}
