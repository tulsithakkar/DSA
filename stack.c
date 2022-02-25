//stack(last in first out)
#include<stdio.h>
int stack[10],top=-1,size=5;
void push()
{
	if(top>=size)
	{
		printf("stack overflow\n");
	}
	else
	{
		top++;
		printf("\nenter value ");
	scanf("%d",&stack[top]);
	}
}
void pop()
{
	if(top==-1)
	{
		printf("\nstack underflow\n");
	}
	else
	{
		printf("deletefd value is %d\n",stack[top]);
		top=top-1;
	}

}
void display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf(" %d ",stack[i]);
	}
}
int main()
{
	int i,ch;
	do{
		printf("\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.display\n");
		printf("4.exit\n");
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("push function\n");
					push();
					break;
			case 2:printf("pop function\n");
					pop();
					break;
			case 3:printf("\ndisplay\n");
					display();
					break;
			case 4:printf("exit");
					break;
			default:printf("enter from the given option");
					break;

		}

	}while(ch!=4);
}
