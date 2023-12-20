#include<stdio.h>
void read(int a[],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        printf("Enter element %d: ",i);
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
    for (i = 1; i <=n; i++)
    {
        printf("%d ",a[i]);
    }
        printf("\n");
}
void heapify(int a[],int i,int size)
{
    int lar,lc,rc;
    lar=i;
    lc=2*i;
    rc=2*i+1;
    if (rc<=size && a[lar]<a[rc])
    {
        lar=rc;
    }
    if (lc<=size && a[lar]<a[lc])
    {
        lar=lc;
    }  
    if (lar!=i)
    {
        swap(&a[lar],&a[i]);
        heapify(a,lar,size);
    }
}
void build_heap(int a[],int n)
{
    int i;
    for ( i = n/2; i >=1; i--)
    {
        heapify(a,i,n);
    }
}
void heap_sort(int a[],int n)
{
    int i;
    int size=n;
    build_heap(a,n);
    for (i = 1; i < n; i++)
    {
        swap(&a[1],&a[size]);
        size--;
        heapify(a,1,size);
    }
}
void main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int a[n];
    read(a,n);
    heap_sort(a,n);
    display(a,n);
}