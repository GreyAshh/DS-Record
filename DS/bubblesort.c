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
    int i,j;
    for (i=0;i<n-1;i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if (a[j]>a[j+1])
            {
                swap(&a[j],&a[j+1]);
            }
            
        }
        
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