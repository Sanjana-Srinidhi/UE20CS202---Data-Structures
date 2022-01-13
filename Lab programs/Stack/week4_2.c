#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define Max 100

typedef struct stack
{
    char a[Max];
    int top;
}stack;

void init(stack *s);
void push(stack *s,char ele);
char pop(stack *s);
int convert(char x,int o1,int o2);


int main()
{
    stack s;
    char x;
    init(&s);
    int o1;
    int o2;
    int res;
    printf("Enter the postfix expression: ");
    while((x=getchar())!='\n')
    {
        if(isdigit(x))
        {
            push(&s,x-48);
        }
        else
        {
            o2=pop(&s);
            o1=pop(&s);
            res=convert(x,o1,o2);
            push(&s,res);
        }
    }
    res=pop(&s);
    printf("Result: %d",res);
    return 0;
}

int convert(char x,int o1,int o2)
{
    if(x=='+')
        return(o1+o2);
    if(x=='-')
        return(o1-o2);
    if(x=='*')
        return(o1*o2);
    if(x=='/')
            return(o1/o2);
    if(x=='%')
            return(o1%o2);
}

void init(stack *s)
{
    s->top=-1;
}

void push(stack *s,char ele)
{
    s->top=s->top+1;
    s->a[s->top]=ele;
}

char pop(stack *s)
{
    int x;
    x=s->a[s->top];
    s->top=s->top-1;
    return x;
}
