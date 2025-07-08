#include<stdio.h>
void main()
{
	int b, p, i=1, ans;
	printf("Enter base : ");
	scanf("%d",&b);
	printf("Enter Power : ");
	scanf("%d",&p);
	
	for(i=1;i<=p;i++)
	{
		ans = ans*b;
	}
	printf("Answer = %d",ans);
}
