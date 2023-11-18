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
void merge_array(int a[],int first,int part,int end)
{
    int i,j,k;
    int temp[end+1];
    i=first;k=0;
    j=part;
    while (i<part && j<=end)
       {
            if (a[i]<a[j])
            {
                temp[k++]=a[i++];
            }
            else
            {
                temp[k++]=a[j++];
            }            
       }
    while (i<part)
       {
            temp[k++]=a[i++];
       }
    while (j<=end)
        {
            temp[k++]=a[j++]; 
        }
    for (i=first,k=0; i<=end; i++,k++)
    {
        a[i]=temp[k];
    }    
}
void merge(int a[],int start,int end)
{
    int mid;
    if (start<end)
    {
        mid=(start+end)/2;
        merge(a,start,mid);
        merge(a,mid+1,end);
        merge_array(a,start,mid+1,end);
    }
    
}
void  main()
{
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int a[n];
    read(a,n);
    merge(a,0,n-1);
    display(a,n);
}