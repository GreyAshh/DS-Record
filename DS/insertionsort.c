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
void sort(int a[],int n)
{
    int i,j,key;
    for (i=1;i<n;i++)
    {
       key=a[i];
       j=i-1;
       while (j>=0 && a[j]>key)
       {
            a[j+1]=a[j];
            j--;
       }
        a[j+1]=key;       
    }
    
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