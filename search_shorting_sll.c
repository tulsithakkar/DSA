#include<stdio.h>
#include<stdlib.h>
int c;
struct list
{
	int id;
	struct list *next;
}*head,*node,*tem,*tem1,*last;
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
int  count()
{
	c=0;
	tem=head;
	while(tem!=NULL)
	{
		c=c+1;
		tem=tem->next;
	}
	return c;
}
void searchbydata()
{
	int s,i,a=0;
	count();
	tem=head;
	printf("\n enter the id for search");
	scanf("%d",&s);
	for(i=1;i<=c;i++)
	{
		if(tem->id==s)
		{
			a=1;
			printf("\n %d on index %d",s,i);
		}
		tem=tem->next;
	}
	if(a==0)
	{
		printf("\nid not found");
	}
}
void searchbyindex()
{
	int index,i,a=0;
	count();
	printf("\n enter the index which you want to search");
	scanf("%d",&index);
	tem=head;
	for(i=1;i<=c;i++)
	{
		if(i==index)
		{
			a=1;
			printf("index %d= data %d",index,tem->id);
		}
		tem=tem->next;
	}
	if(a==0)
	{
		printf("\n index nott found");
	}
	
}
void shorting()
{
	tem=head;
	int sid;
	while(tem!=NULL)
	{
		tem1=tem->next;
		while(tem1!=NULL)
		{
			if(tem->id>tem1->id) 
			{
				sid=tem->id;
				tem->id=tem1->id;
				tem1->id=sid;
			}
			tem1=tem1->next;
		}
		tem=tem->next;
	}
	display();
}
void sum()
{
	int t=0;
	tem=head;
	while(tem!=NULL)
	{
		t=t+tem->id;
		tem=tem->next;
	}
	printf("\nSum is %d",t);
}
void oddeven()
{
	int evenc=0,oddc=0;
	tem=head;
	while(tem!=NULL)
	{
		if(tem->id%2==0)
		evenc=evenc+1;
		else
		oddc=oddc+1;
		tem=tem->next;
	}
	printf("\nEven nodes are : %d\n",evenc);
	printf("odd nodes are : %d\n",oddc);
}
void main()
{
	int ch;
	do
	{
	 printf("\n1.insert at last");
	 printf("\n2.print");
	 printf("\n3.search by data");
	 printf("\n4.search by index");
	 printf("\n5.shorting");
	 printf("\n6.sum of the node");
	 printf("\n7.find odd-even node from the list");
	 printf("\n8.exit");
	 printf("\n enter your choice");
	 scanf("%d",&ch);
	 switch(ch)
	 {
	 	case 1:insertatlast();
	 			break;
	 	case 2:display();
	 			break;
	 	case 3:searchbydata();
	 			break;
	 	case 4:searchbyindex();
	 			break;
	 	case 5:shorting();
	 			break;
	 	case 6:sum();
	 			break;
	 	case 7:oddeven();
	 			break;
	 	case 8: printf("\nbye...");
	 			break;
	 	default:printf("\nenter from the given option");
	 			break;
		}	
	}while(ch!=8);
}

