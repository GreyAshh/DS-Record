#include<stdio.h>
#define size 10
int a[size];
int top=0;

int is_empty() 
{
    if(top==0)
        return 0;
    else    
        return 1;
}
int is_full()
{
    if(top>=size) 
        return 0; 
    else
        return 1;
}
void push(int value)
{
    if(is_full()==0)
        printf("Stack is full.\n");
    else
        a[top++]=value; 
}
int pop()
{
    if(is_empty()==0) 
        printf("Stack is empty.\n");
    else
        return a[--top]; 
}
int peek()
{
    if(is_empty()==0) 
        printf("Stack is empty.\n");
    else
        printf("Top Element: %d\n",a[top-1]);
}
void display()
{
    int i;
    for (i=top-1;i>=0;i--)
    {
        printf("%d\n",a[i]);
    }
    
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
        }
    }while(ch!=5);
}