#include<stdio.h>
#define msize 10
int a[msize];
int size=1;
void swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
int isfull()
{
    if (size>msize)
        return 1;
    else
        return 0;
}
int isempty()
{
    if (size==1)
        return 1;
    else
        return 0;
}
void insert(int value)
{
    int curr,parent;
    if (isfull()==1)
    {
        printf("Queue full.");
    }
    else
    {
        curr=size;
        size++;
        a[curr]=value;
        parent=curr/2;
        while (parent>=1 && a[curr]<a[parent])
        {
            swap(&a[curr],&a[parent]);
            curr=parent;
            parent=curr/2;
        }
    }
}
void heapify(int a[],int i,int size)
{
    int small,lc,rc;
    small=i;
    lc=2*i;
    rc=2*i+1;
    if (rc<=size && a[small]>a[rc])
    {
        small=rc;
    }
    if (lc<=size && a[small]>a[lc])
    {
        small=lc;
    }  
    if (small!=i)
    {
        swap(&a[small],&a[i]);
        heapify(a,small,size);
    }
}
int delete()
{
    int value;
    if (isempty()==1)
    {
        printf("Queue empty.");
    }
    else
    {
        value=a[1];
        a[1]=a[--size];
        heapify(a,1,size);
        return value;
    }
}
void display()
{
    int i;
    printf("The Queue is,\n");
    for (i = 1; i <size; i++)
    {
        printf("%d ",a[i]);
    }
        printf("\n");
}
void main()
{
    int ch,value,v;
    printf("Enter the required options.\n1.Insert element\n2.Delete element\n3.Display elements\n4.Exit\n");
    do
    {
        printf("Enter Option: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter the value to be inserted: "); 
                    scanf("%d", &value);
                    insert(value);
                    break;
            case 2: v=delete(); 
                    printf("Value deleted: %d\n",v);
                    break;
            case 3: printf("The queue is, \n"); 
                    display();
                    break;
            case 4: printf("Exiting the program.\n");
                    break;
            default:printf("Wrong input.\n");
        }
    }while(ch!=4);
}