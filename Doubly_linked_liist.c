//dobaly linked list all the basic opration

#include <stdio.h>
#include <stdlib.h>
int c;
struct list	//structure
{
	int id;
	struct list *pre;		
	struct list *next;
}*head=NULL,*tem,*last,*node,*tem1,*p,*n;
void count()
{
	 c=0;
	tem=head;
	while(tem!=NULL)
	{
		c=c+1;
		tem=tem->next;
	}
	printf("\ntotal number of node=%d\n",c);	
}
void insertatfirst()
{
	node=(struct list*)malloc(sizeof(struct list));
	printf("\n enter the data");
	scanf("%d",&node->id);
	node->next=NULL;
	node->pre=NULL;
	if(head==NULL)
	{
		head=node;
	}
	else
	{	
		node->next=head;
		head->pre=node;
		head=node;
	}
}
void insertatlast()
{
	node=(struct list*)malloc(sizeof(struct list));
	printf("\nenter id:  ");
	scanf("%d",&node->id);
	node->next=NULL;
	node->pre=NULL;
	if(head==NULL)
	{
		head=last=node;
	}
	else
	{
		last->next=node;
		node->pre=last;
		last=node;
	}
}
void insertatindex()
{
	int index;
	count();
	printf("\nenter index: ");
	scanf("%d",&index);
	int i=1;
	if(index==1)
	{
		insertatfirst();
	}
	else if(index==c+1)
	{
		insertatlast();
	}
	else if(index> c+1)
	{
		printf("\nNot vaild index try again");
		insertatindex();
	}
	else 
	{
		node=(struct list*)malloc(sizeof(struct list));
		node->next=NULL;
		node->pre=NULL;
		tem=head;
		printf("\nenter id:  ");
		scanf("%d",&node->id);
		while(i!=index-1)
		{
			i++;
			tem=tem->next;
		}
			node->pre=tem;
			node->next=tem->next;
			tem->next->pre=node;
			tem->next=node;
	}
}
void display()
{
	if(head==NULL)
	{
		printf("\nlink list is empty");
	}
	else
	{
	tem=head;
	while(tem!=NULL)
	{
		printf("%d\n",tem->id);
		tem=tem->next;
	}
	}
}
void deleteatfirst()
{
	if(head==NULL)
	{
		printf("\nliked list is empty\n");	
	}
	else
	{
		tem=head;
		if(head->next==NULL)
		{
			printf("\n this is the last node of the list");
			head=NULL;
		}
		else
		{
			head=tem->next;
			head->pre=NULL;
		}
		free(tem);
	}
}
void deleteatlast()
{
	tem=last;
	if(head==NULL)
	{
		printf("\nliked list is empty");
	}
	else
	{
		if(head==last)
		{
			printf("\n It was the last node of the list");
			head=last=NULL;
		}
		else
		{
			while(tem->next!=NULL)
			{
				tem=tem->next;
			}
			last=tem->pre;
			last->next=NULL;
		}
	free(tem);	
	}
}
void deleteatindex()
{
	int index;
	count();
	printf("\n enter index for which you want yo delete");
	scanf("%d",&index);
	if(index==1)
	{
		deleteatfirst();
	}
	else if(index==c)
	{
		deleteatlast();
	}
	else if(index>c)
	{
		printf("\nindex is not available try again");
		deleteatindex();
	}
	else
	{
		tem=head;
		int i=1;
		while(i!=index)
		{
			i++;
			tem=tem->next;
		}
		n=tem->next;
		p=tem->pre;
		p->next=n;
		n->pre=p;
		//tem->pre->next=tem->next;
		//tem->next->pre=tem->pre;
		
		free(tem);
	}
}
void main()
{
	int ch;
	do
	{
	printf("\n1.insert at first\n");
	printf("2.insert at last\n");
	printf("3.insert in between\n");
	printf("4.print the link list\n");
	printf("5.delete at first\n");
	printf("6.delete at last\n");
	printf("7.delete at specific index\n");
	printf("8.exit \n");
	printf("enter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:insertatfirst();
				break;
		case 2:insertatlast();
				break;		
		case 3:	insertatindex();
				break;
		case 4:printf("lisk list \n");
				display();
				break;
		case 5:deleteatfirst();
				break;
		case 6:deleteatlast();
				break;
		case 7:deleteatindex();
				break;
		case 8: printf("\n bye....");
				break;
		default:printf("\nenter from the given option");
	 			break;
	}
	}while(ch!=8);
}
