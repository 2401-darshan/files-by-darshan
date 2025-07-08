#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n, i;
	printf("Enter Size : ");
	scanf("%d",&n);
	
	int *arr = (int *)malloc(sizeof(int));
	for(i=0;i<n;i++) {
		printf("Enter array element arr[%d] : ",i);
		scanf("%d",arr+i);
	}
	int max =*(arr+0);
	for(i=1;i<n;i++) {
		if(*(arr+i)>max) {
			max = *(arr+i);
		}
	}
	printf("Maximum = %d",max);
}