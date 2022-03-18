#include<stdio.h>
void bsearch(int a[],int n,int key)
{
    int low,high,mid,flag=0;
    low=0;
    high=n-1;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(key==a[mid])
        {
            printf("\n%d found on %d index",key,mid);
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
    int arr[100],n,key,i;
    printf("\n enter the size of array");
    scanf("%d",&n);
    printf("\nenter data in asorder");
    for(i=0;i<n;i++)
    {
        printf("\nenter the data for index arr[%d]:  ",i);
        scanf("%d",&arr[i]);
    }
    printf("\nenter the value for search ");
    scanf("%d",&key);
    bsearch(arr,n,key);
}
