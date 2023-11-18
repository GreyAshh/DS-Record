#include<stdio.h>
#define size 100
char a[size];
int top=0;

int is_empty() 
{
    if(top==0)
        return 1;
    else    
        return 0;
}
int is_full()
{
    if(top>size) 
        return 1; 
    else
        return 0;
}
void push(char value)
{
    if(is_full()==1)
        printf("Stack is full.\n");
    else
        a[top++]=value; 
}
char pop()
{
    if(is_empty()==1) 
        printf("Stack is empty.\n");
    else
        return a[--top]; 
}
int is_operator(char c)
{
    if (c=='+' || c=='-' || c=='*' || c=='/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void evaluate(char* exp)
{
    int i=0;
    int num1,num2,res;
    while (exp[i]!='\0')
    {
        if (is_operator(exp[i])==0)
        {
            push(exp[i] - '0');
        }
        else
        {
            num1=pop();
            num2=pop();
            switch (exp[i])
            {
                case '+':res=num2+num1;
                        break;
                case '-':res=num2-num1;
                         break;
                case '*':res=num2*num1;
                         break;
                case '/':res=num2/num1;
                         break;
            }
            push(res);
        }
        i++;
    }
    printf("Result: %d\n", pop());
}
void main()
{
    char exp[100];
    int i=0;
    printf("Enter the expression: ");
    scanf("%s",exp);
    while (is_operator(exp[i]) == 0)
    {
        push(exp[i] - '0'); 
        i++;
    }
    evaluate(exp);
}