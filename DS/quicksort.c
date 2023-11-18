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
int partition(int a[],int start,int end)
{
    int i,j,key;
    key=a[start];
    i=start+1;
    j=end;
    while (i<j)
    {
        while (a[i]<key && i<end)
        {
            i++;
        }
        while (a[j]>key && j>start)
        {
            j--;
        }
        if (i<j)
        {
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[start],&a[j]);
    return j;
}
void quick(int a[],int start,int end)
{
    if(start<end)
    {
        int pos;
        pos=partition(a,start,end);
        quick(a,start,pos-1);
        quick(a,pos+1,end);
    }
}
void  main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int a[n];
    read(a,n);
    quick(a,0,n-1);
    display(a,n);
}