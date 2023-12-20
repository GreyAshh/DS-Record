#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int info;
    struct Node *next;
};
typedef struct Node node;

node *top=NULL;

node *newnode()
{
    node *p;
    p=(node*)malloc(sizeof(node));
    return p;
}

void push(int value)
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
        p->next=top;
        top=p;
    }
}
int pop()
{
    int item;
    if (top==NULL)
    {
        printf("Empty stack.\n");

    }
    else
    {
        node *p;
        p=top;
        top=top->next;
        item=p->info;
        free(p);
        return item;
    }
    return;
}
int peek()
{
    return top->info;
}
void display()
{
    node *current;
    current=top;
    while (current!=NULL)
    {
        printf("%d ",current->info);
        current=current->next;
    }
    printf("\n");
}
void main()
{
    int ch,value;
    printf("Enter the required options.\n1.Push element\n2.Pop element\n3.Peek element\n4.Display elements\n5.Exit\n");
    do
    {
        printf("Enter Option: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the value to be pushed: ");
                    scanf("%d", &value);
                    push(value); 
                    break;
            case 2: printf("Value Poped: %d\n",pop());
                    break;
            case 3: peek();
                    break;
            case 4: printf("The stack is, \n");
                    display();
                    break;
            case 5: printf("Extting the program. \n");
                    break;
            default:printf("Wrong input.\n");
                    break;
        }
    }while(ch!=5);
}