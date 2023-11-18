#include<stdio.h>
#define size 5
int a[size];
int f=-1;
int r=-1;

int is_empty()
{
    if(f==-1)
        return 1;
    else
        return 0;
}

int is_full()
{
    if(f==(r+1)%size)
        return 1;
    else
        return 0;    
}
void insert(int value)
{
    if(is_full()==1) 
        printf("Queue is full.\n");
    else
        {  
            if(is_empty()==1)
            {
                f=0;
                r=0;
            }
            else
            {
                r=(r+1)%size;
            }
            a[r]=value;
        }
}
int delete()
{
    int val;
    if (is_empty()==1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        val=a[f];
        if (f==r)
        {
            f=-1;
            r=-1;
        }
        else
        {
            f=(f+1)%size;
        }
    }
    return val;
}
void display()
{
    int i=f;
    if (is_empty()==1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        do
        {
            printf("%d ",a[i]);
            i=((i+1)%size);
        } while (i!=(r+1)%size);
        printf("\n");
    }   
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