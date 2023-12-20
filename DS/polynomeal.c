#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int expo;
    int coeff;
    struct Node *next;
};
typedef struct Node node;

node *newnode()
{
    node *p;
    p=(node*)malloc(sizeof(node));
    return p;
}

node* read()
{
    int c,e;
    int ch;
    node *curr,*head;
    head=newnode();
    curr=head;
    do
    {
        printf("Enter the coefficiant: ");
        scanf("%d",&c);
        printf("Enter the exponent   : ");
        scanf("%d",&e);
        curr->coeff=c;
        curr->expo=e;
        printf("Any more values (1/0): ");
        scanf("%d",&ch);
        if (ch==1)
        {
            curr->next=newnode();
            curr=curr->next;
        }
        
    } while (ch!=0);
    curr->next=NULL;
    return head;
}

node* add(node *a,node *b)
{
    node *c,*curr;
    c=newnode();
    curr=c;
    while (a!=NULL && b!=NULL)
    {
        if (a->expo==b->expo)
        {
            curr->coeff=a->coeff+b->coeff;
            curr->expo=a->expo;
            a=a->next;
            b=b->next;
        }
        else
        {
            if (a->expo>b->expo)
            {
                curr->coeff=a->coeff;
                curr->expo=a->expo;
                a=a->next;
            }
            else
            {
                curr->coeff=b->coeff;
                curr->expo=b->expo;
                b=b->next;                
            }
        }
        if (a!=NULL || b!=NULL)
        {
            curr->next=newnode();
            curr=curr->next;
        }
    }
    if (a!=NULL || b!=NULL)
    {
        curr->next=newnode();
        curr=curr->next;
    } 
    while (a!=NULL)
    {
        curr->coeff=a->coeff;
        curr->expo=a->expo;
        a=a->next;
        if (a!=NULL)
        {
            curr->next=newnode();
            curr=curr->next;
        }
    }
    while (b!=NULL)
    {
        curr->coeff=b->coeff;
        curr->expo=b->expo;
        b=b->next;
        if (b!=NULL)
        {
            curr->next=newnode();
            curr=curr->next;
        }
    }
    curr->next=NULL;
    return c;      
}
void display(node *c)
{
    node *curr;
    curr=c;
    printf("\n");
    while (curr!=NULL)
    {
        printf("%d x^%d",curr->coeff,curr->expo);
        if (curr->next!=NULL)
        {
            printf(" + ");
        }
        curr=curr->next;
    }
    printf("\n");
}
void main()
{
    node *a,*b,*c;
    printf("Enter the first polynomeal: \n");
    a=read();
    display(a);
    printf("Enter the second polynomeal: \n");
    b=read();
    display(b);
    printf("Added polynomeal is, \n");
    c=add(a,b);
    display(c);
}