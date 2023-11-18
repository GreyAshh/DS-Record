#include <stdio.h>
#define size 10
char a[size];
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
void rev(char s[])
{
    int i;
    for (i=0; s[i]!='\0'; i++)
    {
        push(s[i]);
    }
    printf("Reverse of the String: ");
    while (is_empty()==1)
    {
        printf("%c",pop());
    }
    printf("\n");   
}
void main()
{
    char s[20];
    printf("Enter the String: ");
    scanf("%s",s);
    rev(s);
}