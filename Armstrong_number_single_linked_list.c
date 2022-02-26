////only add armstrong number in linked list
#include<stdio.h>
#include<stdlib.h>
int cid,c,flag,i;
struct list
{
	int id;
	struct list *next;
	
}*head=NULL,*last=NULL,*tem,*tem1,*node;
int check()
{
	int sum=0,n,x;
	printf("\nenter id:");
	scanf("%d",&cid);
	n=cid;
	while(n>0)
	{
	x=n%10;
	n=n/10;
	sum=sum+(x*x*x);
	}
	if(sum==cid)
	{
		return cid;
	}
	else
	{
		printf("not vaild number try again");
		check();
	}
}
void count()
{
	tem=head;
	c=0;
	while(tem!=NULL)
	{
	c=c+1;
	tem=tem->next;
	}
	printf("\ntotal node= %d",c);
}
void insertatfirst(int cid)
{
	node=(struct list*)malloc(sizeof(struct list));
	node->next=NULL;

	node->id=cid;
	if(head==NULL)
	{
		head=last=node;
	}
	else
	{
		node->next=head;
		head=node;
	}
}
void insertatlast(int cid)
{
	node=(struct list*)malloc(sizeof(struct list));
	node->next=NULL;
	node->id=cid;
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
void insertatmid(int cid)
{
	int index;
	count();
	printf("\nenter index");
	scanf("%d",&index);
	
	int i=1;
	if(index==1)
	{
		insertatfirst(cid);
	}
	else if(index == c+1)
	{
		insertatlast(cid);
	}
	else if(index > c+1 || index<1)
	{
		printf("\ninvaild index try again");
		insertatmid(cid);
	}
	else
	{
		node=(struct list*)malloc(sizeof(struct list));
		node->next=NULL;
		tem=head;
		node->id=cid;
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
	printf("\n list is empty");

	}
	else
	{
	tem=head;
	while(tem!=NULL)
	{
	printf("%d->",tem->id);
	tem=tem->next;
	}
}
}
void deleteatfirst()
{
	if(head==NULL)
	{
		printf("\nlist is empty");
	}
	else
	{
		tem=head;
	 	if(head->next==NULL)
		{
			printf("\nthis the the last node of the list");
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
void deleteatmid()
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
	else if(index>c || index<1)
	{
		printf("\nindex is not available try again");
		deleteatmid();
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
		printf("\n1.insert armstrong number at first");
		printf("\n2.insert armstrong number at last");
		printf("\n3.insert armstrong number at mid");
		printf("\n4.display linked list");
		printf("\n5.delete at first");
		printf("\n6.delete at last");
		printf("\n7. delete at mid");
		printf("\n8.exit");
		printf("\n enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:cid=check();
					insertatfirst(cid);
					break;
			case 2:cid=check();
					insertatlast(cid);
					break;
			case 3:cid=check();
					insertatmid(cid);
					break;
			case 4:display();
					break;
			case 5:deleteatfirst();
					break;
			case 6:deleteatlast();
					break;
			case 7:deleteatmid();
					break;
			case 8:printf("\nbye..");
					break;
			default:printf("enter from the given options");
					break;
		}
		
	}while(ch!=8);
}



