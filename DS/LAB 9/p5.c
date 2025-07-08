#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n, i, j;
	printf("Enter Size : ");
	scanf("%d",&n);
	
	int *arr = (int *)malloc(sizeof(int));
	for(i=0;i<n;i++) {
		printf("Enter array element arr[%d] : ",i);
		scanf("%d",arr+i);
	}
	for(i=0;i<n-i;i++) {
		for(j=0;j<n-i-1;j++) {
			if(*(arr+j+1) < *(arr+j)) {
				int temp = *(arr+j);
				*(arr+j) = *(arr+j+1);
				*(arr+j+1) = temp;
			}
		}
	}
	for(i=0;i<n;i++) {
		printf("%d\n",*(arr+i));
	}
}
