#include<stdio.h>
#include<stdlib.h>
void main()
{
	int *a = (int *)malloc(sizeof(int));
	char *b = (char *)malloc(sizeof(char));
	float *c = (float *)malloc(sizeof(float));
	
	printf("Enter Integer : ");
	scanf("%d",a);
	
	fflush(stdin);
	printf("Enter Character : ");
	scanf("%c",b);
	
	printf("Enter float: ");
	scanf("%f",c);
	
	printf("Integer : %d", *a);
	printf("\nCharacter : %c", *b);
	printf("\nFloat : %f", *c);
	printf("\nInteger : %d", &a);
	printf("\nCharacter : %c", &b);
	printf("\nFloat : %f", &c);
	
	free(a);
	free(b);
	free(c);
}
