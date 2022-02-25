//infix to post-fix 
#include<stdio.h>
char stack[15];
int top=-1;
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

void main()
{
	char exp[15], *e;
	printf("Enter infix notation: ");
	scanf("%s",exp);
	e=exp;
	printf("\n postfix notation is: ");
	while(*e!='\0')
	{
		if(isalnum(*e))
		{
			printf("%c",*e); 
		}
		else
		{
			while(priority(stack[top])>= priority(*e)) 
			{
					printf("%c", pop());
			}
			push(*e);
		}
		e++;
	}
	while(top!=-1)
	{
		printf("%c",pop());
	}

}
