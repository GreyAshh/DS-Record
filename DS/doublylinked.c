#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node node;

node *head=NULL;
node *tail=NULL;

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
    p->prev=NULL;
    if (head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
        head->prev=p;
        head=p;
    }
}

void insert_last(int value)
{
    node *p;
    p=newnode();
    p->info=value;
    p->prev=tail;
    p->next=NULL;
    if (head==NULL)
    {
        head=p;
        tail=p;
    }
    else
    {
        tail->next=p;
        tail=p;
    }
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
        if(current->next==NULL)
            tail=p;
        else
            current->next->prev=p;
        p->next=current->next;
        p->prev=current;
        current->next=p;
    }
}
void insert_before(int value, int before)
{
    node *current;
    current=head; 
    while(current!=NULL && current->info!=before)
    {
        current=current->next;
    } 
    if(current==NULL) 
        printf("No such nodes exist.");
    else
    {
        node* p;
        p=newnode(); 
        p->info=value; 
        if (current->prev==NULL)   
            head=p;
        else
           current->prev->next=p; 
        p->prev=current->prev;
        p->next=current;
        current->prev=p;
    }
}
void delete(int value)
{
    node *current;
    current=head; 
        while(current!=NULL && current->info!=value)
    {
        current=current->next;
    }
    if(current==NULL) 
        printf("No such nodes exist.");
    else
    {
        if (current->prev==NULL)
            head=current->next;
        else
            current->prev->next=current->next;
        if(current->prev==NULL)
            tail=current->prev;
        else
            current->next->prev=current->prev;
        free(current);    
    }
}

void display_lr()
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
void display_rl()
{
    node *current;
    current=tail;
    while (current!=NULL)
    {
        printf("%d ",current->info);
        current=current->prev;
    }
    printf("\n");
}
void main()
{
    int ch,value,other;
    printf("Enter the required options.\n1.Insert element first\n2.Insert element last\n3.Insert element before\n4.Insert element after\n5.Delete element\n6.Display elements(left to right)\n7.Display elements(right to left)\n8.Exit\n");
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
                    insert_last(value);
                    break;
            case 3: printf("Enter the value to be inserted: "); 
                    scanf("%d",&value); 
                    printf("Enter the value before: "); 
                    scanf("%d",&other); 
                    insert_before(value,other); 
                    break;
            case 4: printf("Enter the value to be inserted: "); 
                    scanf("%d",&value); 
                    printf("Enter the value after: "); 
                    scanf("%d",&other); 
                    insert_after(value, other); 
                    break;
            case 5: printf("Enter the value to be deleted: "); 
                    scanf("%d",&value);
                    delete(value);
                    break;
            case 6: printf("The linked list is, \n"); 
                    display_lr();
                    break;
            case 7: printf("The linked list is, \n"); 
                    display_rl();
                    break;
            case 8: printf("Exiting the program");
                    break;
            default:printf("Wrong input");
                    break;
        }
    }while(ch!=8);
}