//infix to prefix
#include<stdio.h>
#include <string.h>  
char stack[15];
char result[15];
int top=-1;
int x=0;
void push(char c)
{
top=top+1;
stack[top]=c;
}
char pop()
{
	if(top==-1)
	return -1;
	else
	return stack[top--];
}

int priority(char c)
{
	if(c=='+' || c=='-')
	return 1;
	if(c=='*' || c=='/')
	return 2;
	if(c=='^' || c=='$')
	return 3;
}
void ans(char c)
{
	result[x++]=c;
}
void main()
{
	char exp[15], *e,*r_exp;
	printf("Enter infix notation: ");
	scanf("%s",exp);
	
	r_exp=strrev(exp);
	e=r_exp;
	printf("\n postfix notation is: ");
	while(*e!='\0')
	{
		if(isalnum(*e))
		{
				ans(*e);
		}
		else
		{
			while(priority(stack[top])> priority(*e)) 
			{
				ans(pop());	
			}
			push(*e);
		}
		e++;
	}
	while(top!=-1)
	{
	ans(pop());
	}
	printf("%s",strrev(result));

}
