#include <stdio.h>
#include <string.h>
char stack[100];
int top = -1;

void push(char c)
{
    if (top >= 100)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[++top] = c;
    }
}
char pop()
{
    if (top == -1)
    {
        printf("Stack Underflow");
    }
    else
    {
        return stack[top--];
    }
}

void check(char string[])
{  
    int i;
    for (i = 0; i < strlen(string); i++)
    {
     
      if(string[i]=='*')
      {
        pop();
      } 
      else
      {
        push(string[i]);
      }
    }
    for(i=0;i<=top;i++){
        printf("%c",stack[i]);
        
    }
}
void main()
{
    char string[100];
    
    printf("enter string:");
    scanf(" %s", string);
    check(string);
    
}
