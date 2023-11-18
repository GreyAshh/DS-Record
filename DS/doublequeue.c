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
void insert_r(int value)
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
void insert_f(int value)
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
                f=(f+size-1)%size;
            }
            a[f]=value;
        }
}
int delete_f()
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
int delete_r()
{
    int val;
    if (is_empty()==1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        val=a[r];
        if (f==r)
        {
            f=-1;
            r=-1;
        }
        else
        {
            r=(r+size-1)%size;
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
    printf("Enter the required options.\n1.Insert element in rear\n2.Insert element in front\n3.Delete element from rear\n4.Delete element from front\n5.Display elements\n6.Exit\n");
    do
    {
        printf("Enter Option: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: printf("Enter the value to be inserted: "); 
                    scanf("%d", &value);
                    insert_r(value);
                    break;
            case 2: printf("Enter the value to be inserted: "); 
                    scanf("%d", &value);
                    insert_f(value);
                    break;
            case 3: v=delete_r(); 
                    printf("Value deleted: %d\n",v);
                    break;
            case 4: v=delete_f(); 
                    printf("Value deleted: %d\n",v);
                    break;
            case 5: printf("The queue is, \n"); 
                    display();
                    break;
            case 6: printf("Exiting the program.\n");
                    break;
            default:printf("Wrong input.\n");
        }
    }while(ch!=6);
}