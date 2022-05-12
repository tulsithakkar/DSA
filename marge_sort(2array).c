#include<stdio.h>
void marge(int a[],int b[],int c[],int m,int n)
{
	int i,j,k;
	i=j=k=0;
	while(i<m && j<n)
	{
		if(a[i]<b[j])
		{
			c[k++]=a[i++];	
		}
		else if(b[j]<a[i])
		{
			c[k++]=b[j++];
		}
		else
		{
			c[k++]=a[i++];
			j++;
			
		}	
	}
	while(i<m)
	{
		c[k++]=a[i++];
	}
	while(j<n)
	{
		c[k++]=b[j++];	
	}
	printf("\n sorted array:");
	for(i=0;i<k;i++)
	{
		printf("%d ",c[i]);
	
	}	
}
void main()
{
	int a[10],b[10],c[20],m,n,i,j,k;
	printf("\nenter the size of first array: ");
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		printf("enter data a[%d] ",i);
		scanf("%d",&a[i]);
	}
	printf("\nenter the size of second array: ");
	scanf("%d",&n);
	for(j=0;j<n;j++)
	{
		printf("enter data b[%d] ",j);
		scanf("%d",&b[j]);
	}
	marge(a,b,c,m,n);
}
