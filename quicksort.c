#include<stdio.h>
void printarray(int a[],int n)
{
	printf("\n");
	int i;
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
int partition(int a[],int low,int high)
{
	int pivot=a[low];
	int i=low+1;
	int j=high;
	int temp;
	do{
	
		while(a[i]<=pivot)
		{
			i++;
		
		}
		while(a[j]>pivot)
		{
			j--;
		}
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			
		}
	}while(i<j);
	//swap j with pivot
	temp=a[low]; 
	a[low]=a[j];
	a[j]=temp;
	return j;
}
void quicksort(int a[],int low,int high)
{
	int partitionindex;
	if(low<high)
	{
	
	partitionindex=partition(a,low,high);
	quicksort(a,low,partitionindex-1);//left side array 
	quicksort(a,partitionindex+1,high);//rightside
	}
}
void main()
{

	int a[100],n,i;
	printf("enter the size of the array ");
	scanf("%d",&n);
	printf("\n");
	for(i=0;i<n;i++)
	{
		printf("enter the value a[%d]: ",i);
		scanf("%d",&a[i]);
	}
	printf("\nbefore the sorting\n");
	printarray(a,n);

	quicksort(a,0,n-1);
	printf("\n after the sorting\n");
	printarray(a,n);
}
