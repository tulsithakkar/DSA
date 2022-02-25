//marge two single linked list 
#include<stdio.h>
#include<stdlib.h>
struct list1
{
	int id1;
	struct list1 *next;
}*head1=NULL,*last1=NULL,*node1,*temp1,*head2=NULL,*last2=NULL;

void insertatfirst()
{
	node1=(struct list1*)malloc(sizeof(struct list1));
	node1->next=NULL;
	printf("\nenter id: ");
	scanf("%d",&node1->id1);
	if(head1==NULL)
	{
		head1=last1=node1;
	}
	else 
	{
		node1->next=head1;
		head1=node1;
	}
}
void display()
{
	temp1=head1;
	if(head1==NULL)
	{
		printf("\nlist is empty");	
	}
	else
	{
	while(temp1!=NULL)
	{
		printf("\n%d->",temp1->id1);
		temp1=temp1->next;
	}
	}
}
void insertatfirst1()
{
	node1=(struct list1*)malloc(sizeof(struct list1));
	node1->next=NULL;
	printf("\nenter id: ");
	scanf("%d",&node1->id1);
	if(head2==NULL)
	{
		head2=node1;
	}
	else 
	{
		node1->next=head2;
		head2=node1;
	}
}
void display1()
{
	temp1=head2;
	if(head2==NULL)
	{
		printf("\nlist is empty");
	}
	else
	{
	while(temp1!=NULL)
	{
		printf("\n%d->",temp1->id1);
		temp1=temp1->next;
	}
	}
}
void marge()
{
	last1->next=head2;
}
void main()
{
	struct list1 l1;
	int ch;
	do
	{
		printf("\n1.insert at first in list 1");
		printf("\n2. display list 1");
		printf("\n3.insert at first in list 2");
		printf("\n4. display list 2");
		printf("\n5. marge 2 list");
		printf("\n6. exit");
		printf("\nenter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: insertatfirst();
					break;
			case 2: printf("\n1st list\n");
					display();
					break;
			case 3: insertatfirst1();
					break;
			case 4: printf("\n2sd list\n");
					display1();
					break;
			case 5:marge();
					display();
					break;
			case 6: printf("\nexit");
					break;
			default:printf("\nenter from the given option");
	 				break;
		}
	}while(ch!=6);

}
