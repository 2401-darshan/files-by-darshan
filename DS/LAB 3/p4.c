#include<stdio.h>
void main()
{
	int n, i;
	printf("Enter n: ");
	scanf("%d",&n);
	
	int arr[n];
	for(i=0;i<n;i++)
	{
		printf("Enter array element arr[%d] : ",i);
		scanf("%d",&arr[i]);
	}
	
	int max=arr[0], min=arr[0], maxp, minp;
	
	for(i=1;i<n;i++)
	{
		if(arr[i]>max){
			max = arr[i];
			maxp = i;
		}
		if(arr[i]<min) {
			min = arr[i];
			minp = i;
		}
	}
	
	printf("Max position is %d",maxp);
	printf("\nMin position is %d",minp);
}
