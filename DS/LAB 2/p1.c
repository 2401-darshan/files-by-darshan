//factorial

#include<stdio.h>
void main()
{
	int n, i=1, ans=1;
	printf("Enter any number you want factorial of it : ");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		ans = ans*i;
	}
	printf("Factorial = %d",ans);
}
