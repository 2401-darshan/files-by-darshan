#include<stdio.h>
void main()
{
	int n, num, index;
	printf("Enter size : ");
	scanf("%d",&n);
	
	int arr[n+1], i;
	for(i=0;i<n;i++)
	{
		printf("Enter array element arr[%d] : ",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter any number to insert : ");
	scanf("%d",&num);
	
	printf("Enter index to insert element : ");
	scanf("%d",&index);
	
	for(i=n;i>=0;i--)
	{
		if(arr[i]==index) {
			arr[i+1]=num;
			break;
		}
		arr[i] = arr[i-1];
	}
	for(i=0;i<=n;i++)
	{
		printf("%d ",arr[i]);
	}
}
