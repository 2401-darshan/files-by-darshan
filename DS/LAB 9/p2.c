#include <stdio.h>
#include <stdlib.h>
void main()
{
	int n, i;
	printf("Enter size of n : ");
	scanf("%d", &n);

	int *arr = (int *)malloc(sizeof(int));
	for (i = 0; i < n; i++)
	{
		printf("Enter array element arr[%d] : ", i);
		scanf("%d", arr + i);
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", *(arr + i));
	}
}