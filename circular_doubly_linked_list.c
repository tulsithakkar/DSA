//circular double linked list all the basic opration
#include<stdio.h>
#include<stdlib.h>
int c;
struct list
{
	int id;
	struct list *pre;
	struct list *next;
}*head=NULL,*last=NULL,*node,*tem,*tem1;
void count()
{
	tem=head;
	c=0;
	do
	{
		c=c+1;
		tem=tem->next;
	}while(tem!=head);
	printf("\n total node: %d",c);
}
void insertatfirst()
{
	node=(struct list*)malloc(sizeof(struct list));
	node->next=NULL;
	node->pre=NULL;
	printf("\nenter id: ");
	scanf("%d",&node->id);
	if(head==NULL)
	{
		node->next=node->pre=node;
		head=last=node;
	}
	else
	{
		node->next=head;
		node->pre=last;
		head->pre=node;
		last->next=node;
		head=node;
		
	}
}
void inseratlast()
{
	node=(struct list*)malloc(sizeof(struct list));
	node->next=NULL;
	node->pre=NULL;
	printf("\nenter id: ");
	scanf("%d",&node->id);
	if(head==NULL)
	{
		node->next=node->pre=node;
		head=last=node;
	}
	else
	{
		node->pre=last;
		node->next=head;
		head->pre=node;
		last->next=node;
		last=node;
	}
}
void insertatmid()
{
	count();
	int index,i=1;
	printf("\n enter the index where you want to insert the data: ");
	scanf("%d",&index);
	if(index==1)
	{
		insertatfirst();
	}
	else if(index==c+1)
	{
		inseratlast();	
	}
	else if(index > c+1)
	{
		printf("\ninvaild index try again");
		insertatmid();
	}
	else
	{
		tem=head;
		node=(struct list*)malloc(sizeof(struct list));
		node->pre=NULL;
		node->next=NULL;
		printf("\n enter id: ");
		scanf("%d",&node->id);
		while(i!=index-1)
		{
			i++;
			tem=tem->next;
		}
		node->pre=tem;
		node->next=tem->next;
		tem->next=node;
		tem->next->pre=node;
	}
}
void print()
{
	tem=head;
	if(head==NULL)
	{
		printf("\nlist is empty");
	}
	else
	{	
	do
	{
		printf("\n%d->",tem->id);
		tem=tem->next;
	}while(tem!=head);
	}
}
void deleteatfirst()
{
	if(head==NULL)
	{
		printf("\n liked list is empty");
	}
	else if(head->next==head)
	{
		printf("\n This the last node of the list");
		head=NULL;
	}
	else
	{
		tem=head;
		head=head->next;
		head->pre=last;
		last->next=head;
		free(tem);	
	}
}
void deleteatlast()
{
	tem=head;
	if(head==NULL)
	{
		printf("\n list is empty");
	}
	else if(head->next==head)
	{
		printf("\n This is the last node of the list");
		head=NULL;
	}
	else
	{
		tem=head;
		while(tem->next!=last)
		{
			tem=tem->next;
		}
		free(last);
		last=tem;
		tem->next=head;
		head->pre=last;
	}
}
void deleteatmid()
{
	count();
	int index,i=1;
	printf("\n enter the index : ");
	scanf("%d",&index);
	if(index==1)
	{
		deleteatfirst();
	}
	else if(index==c)
	{
		deleteatlast();
	}
	else if(index > c)
	{
		printf("\n not vaild index try again");
		deleteatmid();
	}
	else
	{
		struct list *n,*p;
		tem=head;
		while(i!=index)
		{
			i++;
			tem=tem->next;
		}	
		n=tem->next;
		p=tem->pre;
		p->next=n;
		n->pre=p;
		//tem->next->pre=tem->pre;
		//tem->pre->next=tem->next;
	}free(tem);
}
void main()
{
	int ch;
	do
	{
	printf("\n");
	printf("\n1 insert at first");
	printf("\n2. inser at last");
	printf("\n3. inser at mid");
	printf("\n4 display list");
	printf("\n5. delete at first");
	printf("\n6.delete at last ");
	printf("\n7.delete at mid");
	printf("\n8.exit");
	printf("\nenter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: insertatfirst();
				break;
		case 2:inseratlast();
				break;
		case 3:insertatmid();
				break;
		case 4:print();
				break;
		case 5:deleteatfirst();
				break;
		case 6:deleteatlast();
				break;
		case 7:deleteatmid();
			break;
		case 8:printf("\nbye..");
				break;
		default:printf("\nenter from the given option");
	 			break;
	}
	}while(ch!=8);
}
