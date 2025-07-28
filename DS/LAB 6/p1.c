#include<stdio.h>
#include<stdlib.h>


int top=-1;
char arr[100];

void push(char x)
{
	if(top>=100)
	{
		printf("Stack Overflow.");
		return;
	}
	top++;
	arr[top]=x;
}

char pop()
{
	if(top<=-1)
	{
		printf("Stack Underflow.");
		return '\0';
	}
	char temp=arr[top];
	top--;
	return temp;
}

void main()
{
	char s[100],c;
	printf("Enter a String=");
	scanf("%s",s);
	
	int i;
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='('|| s[i]=='{' || s[i]=='[' )
		{
			push(s[i]);
		}
		else
		{
			if(top<=-1)
			{
				printf("Invalid paranthesis.");
				return;
			}
			char temp=pop();
			if((s[i]==')'&& temp!='(')|| (s[i]=='}' && temp!='{')||(s[i]==']' && temp !='['))
			{
				printf("Invalid paranthesis.");
				return;
			}
		}
	}
	if(top<=-1)
	{
		printf("Valid Paranthesis.");
		return;
	}
	else
	{
		printf("Invalid paranthesis.");
		return;
	}
}
