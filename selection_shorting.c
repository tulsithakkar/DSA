#include<stdio.h>
void selection(int a[],int n)
{
	int i,j,minindex,temp;
	for(i=0;i<n;i++)
	{
		minindex=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[minindex])
			{
				minindex=j;
			}
		}
		temp=a[i];
		a[i]=a[minindex];
		a[minindex]=temp;
		
	}
	printf("\nOutput after pass %d",i);
	for(i=0;i<n;i++)
	{
		printf("\n arrr[%d]=%d",i,a[i]);
	}
}
void main()
{
	int arr[100],n,i;
	printf("\n nenter the size of the array");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter value arr[%d] ",i);
		scanf("%d",&arr[i]);
	}
	selection(arr,n);
}
