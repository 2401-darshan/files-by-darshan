#include<stdio.h>
void main()
{
	int n, i, flag, po;
	printf("Enter size : ");
	scanf("%d",&n);
	
	int arr[n], n1, n2;
	
	for(i=0;i<n;i++)
	{
		printf("enter array element arr[%d] : ",i);
		scanf("%d",&arr[i]);
	}
	printf("Enter 1st number : ");
	scanf("%d",&n1);
	printf("Enter 2nd number to replace : ");
	scanf("%d",&n2);
	
	for(i=0;i<n;i++)
	{
		if(arr[i]==n1){
			arr[i]=n2;
			po=i;
			break;
		}
	}
	
	for(i=0;i<n;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nindex is %d",po);
}
