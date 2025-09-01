#include<stdio.h>
#include<string.h>
#include<math.h>
int s[100];
int top=-1;
void push(int c)
{
	s[++top]=c;
}
int pop()
{
	return s[top--];
}
void ev_postfix(char postfix[])
{
	int i;
	for(i=0;i<strlen(postfix);i++)
	{
		if(isdigit(postfix[i]))
		{
			push(postfix[i] - '0');
		}
		else
		{
			int operand2 = pop();
			int operand1 = pop();
			switch(postfix[i])
			{
					case '+':
					push(operand1+operand2);
					break;
					
					case '-':
					push(operand1-operand2);
					break;
					
					case '*':
					push(operand1*operand2);
					break;
					
					case '/':
					push(operand1/operand2);
					break;
					
					case '^':
					push(pow(operand1,operand2));
					break;
			}
		}
		 
	}
}
void main()
{
	char postfix[100];
	printf("Enter the postfix=");
	scanf("%s",postfix);
	ev_postfix(postfix);
	printf("Answer is =%d",pop());
	
}
