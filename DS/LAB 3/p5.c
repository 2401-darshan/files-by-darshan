#include<stdio.h>
void main()
{
	int n, i, j, count=0;
	printf("Enter n: ");
	scanf("%d",&n);
	
	int arr[n];
	
	for(i=0;i<n;i++)
	{
		printf("Enter array element arr[%d] : ",i);
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n-1;i++) 
	{
		for(j=i+1;j<n;j++) 
		{
			if(arr[i]==arr[j]) {
				count++;
				break;
			}
		}	
	}
	printf("%d duplicate founded",count);
}
