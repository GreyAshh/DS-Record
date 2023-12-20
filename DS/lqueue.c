#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node node;

node *f=NULL;
node *r=NULL;

node *newnode()
{
    node *p;
    p=(node*)malloc(sizeof(node));
    return p;
}

void insert(int value)
{
    node *p;
    p=newnode();
    if (p==NULL)
    {
        printf("Insufficiant memory.");
    }
    else
    {
        p->info=value;
        p->next=NULL;
        if (r==NULL)
        {
            f=p;
            r=p;
        }
        else
        {
            r->next=p;
            r=p;
        }
    }
}
int delete()
{
    int val;
    if (f==NULL)
    {
        printf("Empty Queue.\n");
    }
    else
    {
        node *p;
        p=f;
        val=f->info;
        if (r==f)
        {
            f=NULL;
            r=NULL;
        }
        else
        {
            f=f->next;
        }
        free(p);
        return val;
    }
    return;
}
void display()
{
    node *current;
    current=f;
    while (current!=NULL)
    {
        printf("%d ",current->info);
        current=current->next;
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