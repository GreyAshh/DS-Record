#include<stdio.h>
void read(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i+1);
        scanf("%d",&a[i]);
    }
}
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void sort(int a[],int n)
{
    int i,j,l,index;
    for (i=0;i<n;i++)
    {
        l=a[0];
        index=0;
        for ( j=1; j<n-i; j++)
        {
            if(l<a[j])
            {
                l=a[j];
                index=j;
            }
        }
        swap(&a[index],&a[n-i-1]);          
    }
    
}
void display(int a[],int n)
{
    int i;
    printf("The sorted array is,\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ",a[i]);
    }
        printf("\n");
}

void  main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int a[n];
    read(a,n);
    sort(a,n);
    display(a,n);
}