#include<stdio.h>
void main()
{
	int n, i, sum=0;
	float avg;
	printf("enter n: ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		sum+=i;
	}
	avg = sum/n;
	printf("Sum = %d",sum);
	printf("\nAverage = %f",avg);
	
}
