#include<stdio.h>
void read(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter element  %d: ",i+1);
        scanf("%d",&a[i]);
    }
}
int search(int a[],int n,int x)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i]==x)
            return i;
    }
    return (-1);
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
    flag=search(a,n,x);
    if (flag==-1)
    {
        printf("The element is not present in the array.");
    }
    else
    {
        printf("The element is present at %d th position in the array.",flag+1);
    }
}