#include<stdio.h>
void main()
{
	int m, n, i, sum=0;
	printf("Enter 1st number : ");
	scanf("%d",&m);
	printf("Enter 2nd number : ");
	scanf("%d",&n);
	
	for(i=m;i<=n;i++)
	{
		sum = sum + i;
	}
	printf("Sum is %d",sum);
}
