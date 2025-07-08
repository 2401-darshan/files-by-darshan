#include<stdio.h>
void main()
{
	int n;
	printf("Enter size n : ");
	scanf("%d",&n);
	
	int a[n][n], b[n][n], c[n][n], i, j, sum=0;
	for(i=0 ; i<n ; i++) {
		for(j=0 ; j<n ; j++) {
			printf("Enter array element a[%d][%d] : ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0 ; i<n ; i++) {
		for(j=0 ; j<n ; j++) {
			printf("Enter array element b[%d][%d] : ",i,j);
			scanf("%d",&b[i][j]);
		}
	}
	for(i=0 ; i<n ; i++) {
		for(j=0 ; j<n ; j++) {
			printf("%d ",a[i][j] + b[i][j]);
		}
		printf("\n");
	}
}
