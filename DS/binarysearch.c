#include<stdio.h>
void read(int a[],int n)
{
    int i;
    printf("Enter element in the sorted order.\n");
    for(i=0;i<n;i++)
    {
        printf("Enter element  %d: ",i+1);
        scanf("%d",&a[i]);
    }
}
int search(int a[],int top,int bot,int x)
{
    int mid;
    if (top<=bot)
    {
        mid=(top+bot)/2;
        if (a[mid]==x)
        {
            return mid;
        }
        else if (a[mid]>x)
        {
            search(a,top,mid-1,x);
        }
        else
        {
            search(a,mid+1,bot,x);
        }       
    }
    else
    {
        return (-1);
    } 
}
void  main()
{
    int x,flag,n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int a[n];
    read(a,n);
    printf("Enter the element to be searched: ");
    scanf("%d",&x);
    flag=search(a,0,n-1,x);
    if (flag==-1)
    {
        printf("The element is not present in the array.");
    }
    else
    {
        printf("The element is present at %d th position in the array.",flag+1);
    }
}