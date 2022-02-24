//single link-list(all The basic opration)
#include <stdio.h>
#include <stdlib.h>
int c;
struct list //structure
{
	int id;
	struct list *next;
}*head=NULL,*tem,*last,*node,*tem1; //pointers
void count()	//count function for count the total  number of nodes
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
	node=(struct list*)malloc(sizeof(struct list));//memory allocation
	printf("\n enter the data");
	scanf("%d",&node->id);
	node->next=NULL;
	if(head==NULL)
	{
		head=node;
	}
	else
	{
		node->next=head;
		head=node;
	}
}
void insertatlast()
{
	node=(struct list*)malloc(sizeof(struct list));
	printf("\nenter id:  ");
	scanf("%d",&node->id);
	node->next=NULL;
	if(head==NULL)
	{
		head=last=node;
	}
	else
	{
		last->next=node;
		last=node;
	}
}
void insertatindex()
{
	int index;
	node=(struct list*)malloc(sizeof(struct list));
	count();
	printf("\nenter index");
	scanf("%d",&index);
	node->next=NULL;
	tem=head;
	int i=1;
	if(index==1)
	{
		insertatfirst();
	}
	else if(index == c+1)
	{
		insertatlast();
	}
	else if(index > c+1)
	{
		printf("\ninvaild index try again");
		insertatindex();
	}
	else
	{
		printf("\nenter id:  ");
		scanf("%d",&node->id);
		while(i!=index-1)
		{
			i++;
			tem=tem->next;
		}
		node->next=tem->next;
		tem->next=node;
	
	}
}
void display()
{
	if(head==NULL)
	{
		printf("\nlink list is empty");
		//main();
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
			printf("\n This is the last node of the list");
			head=NULL;
		}
		else
		{
			head=tem->next;
		
		}
		free(tem);
	}
}
void deleteatlast()
{
	tem=head;
	if(head==NULL)
	{
		printf("\nliked list is empty");
	}
	else
	{
		if(head->next==NULL)
		{
			printf("\nthis is the last node if the list");
			last=head=NULL;
		}
		else
		{
			while(tem->next!=NULL)
			{
				tem1=tem;
				tem=tem->next;
			}
			tem1->next=NULL;
		}
	free(tem);	
	}
}
void deleteatindex()
{
	int index;
	count();
	tem=head;
	
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
		struct list *tem1;
		int i=1;
		while(i!=index)
		{
			tem1=tem;
			i++;
			tem=tem->next;
		}
		tem1->next=tem->next; 
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
	}
	}while(ch!=8);
}
