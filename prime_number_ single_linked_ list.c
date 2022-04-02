// enter prime number as data in single linked list
#include<stdio.h>
#include<stdlib.h>
int cid,flag,i,c;
struct list
{
	int id;
	struct list *next;
}*head=NULL,*LAST=NULL,*node,*tem,*last,*tem1;
int check()
{
	flag=0;
	printf("\n enter id: ");
	scanf("%d",&cid);
	if(cid==1)
	{
		flag=1;
	}
	else
	{
	for(i=2;i<=cid/2 ;i++)
	{
		if(cid%i==0)
		{
		flag=1;
		break;
		}
	}
}
	if(flag==0)
	{
		return cid;
	}
	else
	{
		printf("\n invails number try agian");
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
void inseratfirst(int cid)
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
	count();
	int index;
	printf("\nenter the index where ypou want to insert");
	scanf("%d",&index);
	if(index==1)
	{
	inseratfirst(cid);
	}
	else if(index==c+1)
	{
	insertatlast(cid);
	}
	else if (index > c+1)
	{
	printf("\n not vaild index try again");
	insertatmid(cid);

	}
	else
	{

	i=1;
	node=(struct list*)malloc(sizeof(struct list));
	node->next=NULL;
	node->id=cid;
	tem=head;
	while(i!=index-1)
	{
		i++;
		tem=tem->next;
	}
	node->next=tem->next;
	tem->next=node;
	}

}
void print()
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
	printf("%d\n",tem->id);
	tem=tem->next;
	}
}
}
void deleteatfirst()
{
	tem=head;
	if(head==NULL)
	{
	printf("\nlist is empty");
	}
	else if(head->next==NULL)
	{
	printf("\n Thisd is the last node of the list");
	head=NULL;
	}
	else
	{

	head=head->next;
	}free(tem);
}
void deleteatlast()
{
	tem=head;

	if(head==NULL)
	{
	printf("\nlist is empty");
	}
	else if(head->next==NULL)
	{
	printf("\n Thisd is the last node of the list");
	head=last=NULL;
	}
	else
	{
	while(tem->next!= NULL)
	{
	tem1=tem;
	tem=tem->next;
	}
	last=tem1;
	last->next=NULL;
	}free(tem);
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
	printf("\n1. insert prime number at first");
	printf("\n2. insert prime number at last");
	printf("\n3.insert prime number at mid");
	printf("\n4.printf the list");
	printf("\n5. delete at first");
	printf("\n6. delete at last");
	printf("\n7. delete at mid");
	printf("\n8.exit");
	printf("\n enter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:cid=check();
				inseratfirst(cid);
				break;
		case 2:cid=check();
				insertatlast(cid);
				break;
		case 3:cid=check();
				insertatmid(cid);
				break;
		case 4:print();
		break;
		case 5:deleteatfirst();
		break;
		case 6:deleteatlast();
		break;
		case 7:deleteatmid();
		break;
		case 8:printf("bye...");
		break;
		default:printf("\nenter from the given option");
		break;
	}
	}while(ch!=8);

