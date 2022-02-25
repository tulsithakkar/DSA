//circular single linked list all the basic opration
#include <stdio.h>
#include <stdlib.h>
int c;
struct list  //structure
{
	int id;
	struct list *next;
}*head=NULL,*last=NULL,*temp,*node,*temp1;
void count()
{
	c=0;
	temp=head;
	do
	{
		c=c+1;
		temp=temp->next;
	}while(temp!=head);
	printf("\ntotal node are= %d",c);
}
void insertatfirst()
{
	node=(struct list*)malloc(sizeof(struct list));
	printf("enter data :");
	scanf("%d",&node->id);
	node->next=NULL;
	if(head==NULL)
	{
		head=last=node;
		last->next=head;
	}
	else
	{
		node->next=head;
		last->next=node;
		head=node;
	}
}
void insertatlast()
{
	node=(struct list*)malloc(sizeof(struct list));
	printf("enter data :");
	scanf("%d",&node->id);
	node->next=NULL;
	if(head==NULL)
	{
		head=last=node;
		last->next=head;
	}
	else
	{
		last->next=node;
		node->next=head;
		last=node;
	}
}
void insertatmid()
{
	int index,i=1;
	count();
	printf("\nenter possition");
	scanf("%d",&index);
	if(index==1)
	{
		insertatfirst();
	}
	else if(index==c+1)
	{
		insertatlast();
	}
	else if(index > c+1)
	{
		printf("\n not avilable");
		insertatmid();
	}
	else
	{
		node=(struct list*)malloc(sizeof(struct list));
		node->next=NULL;
		printf("\nenter id:");
		scanf("%d",&node->id);
		while(i!=index-1)
		{
			i++;
			temp=temp->next;
		}
		node->next=temp->next;
		temp->next=node;
	}
}
void print()
{
	temp=head;
	do
	{
		printf("%d-->",temp->id);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}
void deleteatfirst()
{
	head=temp;
	if(head==NULL)
	{
		printf("\n liked list is empty");
	}
	else if(head->next==head)
	{
		printf("\n this is the last node of the list");
		head=NULL;
	}
	else
	{
		head=head->next;
		last->next=head;
	}free(temp);
}
void deleteatlast()
{
	temp=head;	
	if(head==NULL)
	{
		printf("list is empty");
	}
	else if(head->next==head)
	{
		printf("\n This is the last node of the list");
		head=NULL;
	}
	else
	{
		while(temp->next!=last)
		{
			temp=temp->next;
		}	
	temp->next=head;
	free(last);
	last=temp;
	}
}
void delatmid()
{
	count();
	int index,i=1;
	printf("\nenter the index: ");
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
		delatmid();
	}
	else
	{
		temp=head;
		while(i != index)
		{
			temp1=temp;
			temp=temp->next;
			i++;
		}
		temp1->next=temp->next;
		free(temp);
	}
}
int main() {
	int ch;
	do
	{
	printf("\n1.insert at first");
	printf("\n2.insert at last");
	printf("\n3.insert at mid");
	printf("\n4.print list");
	printf("\n5.delete at first");
	printf("\n6.delete at last");
	printf("\n7. delete at mid");
	printf("\n8.exit");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:insertatfirst();
			break;
		case 2:insertatlast();
			break;
		case 3:insertatmid();
			break;
		case 4:print();
			break;
		case 5:deleteatfirst();
			break;
		case 6:deleteatlast();
			break;
		case 7:delatmid();
			break;
		case 8: printf("\n bye....");
				break;
		default:printf("\nenter from the given option");
	 			break;
	}
	}while(ch!=8);
	return 0;
}
