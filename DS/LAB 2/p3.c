#include<stdio.h>
void main()
{
	int n, i, rem, rev=0;
	printf("Enter number : ");
	scanf("%d",&n);
	
	while(n!=0)
	{
		rem = n % 10;
		rev = rev*10 + rem;
		n = n/10;
	}
	printf("%d",rev);	
}
