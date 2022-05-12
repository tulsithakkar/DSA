#include<stdio.h>
void bubble(int a[],int n)
{
	int i,j,temp,issorted=0;
	for(i=0;i<n-1;i++)
	{
	//	issorted=1;
		for(j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				printf("\nSwapping of a[j] and a[j+1] %d %d",a[j],a[j+1]);
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
	//			issorted=0;
			}
		}
	}
	
	printf("\nOutput after pass %d",i+1);
	//if(issorted==1)
	//{
	//	return;
	//}
	printf("\n\nsorted array");
	for(i=0;i<n;i++)
	{
		printf("\na[%d]=%d",i,a[i]);
	}	

}

void main()
{
	int arr[100],n,i;
	printf("\n neter the size of the array ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the value arr[%d] ",i);
		scanf("%d",&arr[i]);
	}
	bubble(arr,n);

}
