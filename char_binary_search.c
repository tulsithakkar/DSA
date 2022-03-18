#include<stdio.h>
void bsearch(char a[],int n,char key)
{
	printf("\n");
    int low,high,mid,flag=0;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(key==a[mid])
        {
            printf("%c found on %d index",key,mid);
            flag=1;
            return;
        }
        else if(key >a[mid])
        {
            low=mid+1;
        }
        else
        {
            high=low-1;
        }
    }
}
void main()
{
    char arr[100],key;
    int i,n;
    printf("\n enter the size of array");
    scanf("%d",&n);
    printf("\nenter data in asorder");
    for(i=0;i<n;i++)
    {
        printf("\nenter the data for index arr[%d]:  ",i);
        scanf("%s",&arr[i]);
    }
    printf("\nenter the value for search ");
    fflush(stdin);
    scanf("%c",&key);
    bsearch(arr,n,key);
}
