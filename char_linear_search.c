#include<stdio.h>
void lsearch(char a[],int n,char key)
{
    int i,flag=0;
    for(i=0;i<n;i++)
    {
        if(a[i]==key)
        {
            printf("\n%c found on %d index",key,i);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\n%c not found",key);
    }
}
void main()
{
    char a[100],key;
    int n,i;
    printf("\nEnter the size of array: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter the data for index a[%d]:  ",i);
        scanf("%s",&a[i]);
    }
    printf("\nEnter the value for search: ");
    fflush(stdin);
    scanf("%c",&key);
    lsearch(a,n,key);
}
