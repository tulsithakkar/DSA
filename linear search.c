#include<stdio.h>
void lsearch(int a[],int n,int key)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("%d found on %d index",key,i);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("%d not found",key);
    }
}
void main()
{
    int arr[100],n,key,i;
    printf("\n enter the size of array");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("enter the data for index arr[%d]:  ",i);
        scanf("%d",&arr[i]);
    }
    printf("\nenter the value for search");
    scanf("%d",&key);
    lsearch(arr,n,key);
}
