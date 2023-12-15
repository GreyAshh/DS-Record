#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node node;

node *head=NULL;

node *newnode()
{
    node *p;
    p=(node*)malloc(sizeof(node));
    return p;
}

void insert_first(int value)
{
    node *p;
    p=newnode();
    p->info=value;
    p->next=head;
    head=p;
}

void insert_after(int value,int after)
{
    node *current;
    current=head;
    while (current!=NULL && current->info!=after)
    {
        current=current->next;
    }
    if (current==NULL)
    {
        printf("No such nodes exist.");
    }
    else
    {
        node *p;
        p=newnode();
        p->info=value;
        p->next=current->next;
        current->next=p;
    }
}
void insert_before(int value, int before)
{
    node *current;
    node *previous;
    current=head; 
    previous=NULL;
    while(current!=NULL && current->info!=before)
    {
        previous=current;
        current=current->next;
    } 
    if(current==NULL) 
        printf("No such nodes exist.");
    else
    {
        node* p;
        p=newnode(); 
        p->info=value; 
        p->next=current; 
        if(previous!=NULL) 
            previous->next=p;
        else
            head=p;
    }
}
void delete(int value)
{
    node *current;
    node *previous;
    current=head; 
    previous=NULL;
        while(current!=NULL && current->info!=value)
    {
        previous=current;
        current=current->next;
    }
    if(current==NULL) 
        printf("No such nodes exist.");
    else
    {
        if(previous==NULL)
        {
            head=current->next;
        }
        else
        {
            previous->next=current->next;
        }
        free(current);
    }
}

void display()
{
    node *current;
    current=head;
    while (current!=NULL)
    {
        printf("%d ",current->info);
        current=current->next;
    }
    printf("\n");
}
void main()
{
    int ch,value,other;
    printf("Enter the required options.\n1.Insert element first\n2.Insert element before\n3.Insert element after\n4.Delete element\n5.Display elements\n6.Exit\n");
    do
    {
        printf("Enter Option: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the value to be inserted: "); 
                    scanf("%d",&value);
                    insert_first(value);
                    break;
            case 2: printf("Enter the value to be inserted: "); 
                    scanf("%d",&value); 
                    printf("Enter the value before: "); 
                    scanf("%d",&other); 
                    insert_before(value,other); 
                    break;
            case 3: printf("Enter the value to be inserted: "); 
                    scanf("%d",&value); 
                    printf("Enter the value after: "); 
                    scanf("%d",&other); 
                    insert_after(value, other); 
                    break;
            case 4: printf("Enter the value to be deleted: "); 
                    scanf("%d",&value);
                    delete(value);
                    break;
            case 5: printf("The linked list is, \n"); 
                    display();
                    break;
            case 6: printf("Exiting the program");
                    break;
            default:printf("Wrong input");
                    break;
        }
    }while(ch!=6);
}