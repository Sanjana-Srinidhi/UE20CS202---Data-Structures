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
char peek(stack *s);
int isempty(stack *s);
int isfull(stack *s);
int precedence(char token);
void convert(char *infix, char *postfix);


int main()
{
    char infix[100];
    char postfix[100];
    printf("Enter the expression: ");
    gets(infix);
    convert(infix,postfix);
    printf("%s",&postfix);
    return 0;
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
    char x;
    x=s->a[s->top];
    s->top=s->top-1;
    return x;
}

char peek(stack *s)
{
    return s->a[s->top];
}

int isempty(stack *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    return 0;
}

int isfull(stack *s)
{
    if(s->top==Max)
    {
        return 1;
    }
    return 0;
}

int precedence(char token)
{
    if(token=='(')
        return 0;
    else if(token=='+' || token=='-')
    {
        return 1;
    }
    else if(token=='*' || token=='/')
    {
        return 2;
    }
    return 3;
}

void convert(char *infix, char *postfix)
{
    stack s;
    init(&s);
    char token;
    char x;
    int i;
    int p;
    p=-1;
    
    for(i=0;infix[i]!='\0';i++)
    {
        token=infix[i];
        if(isalnum(token))
        {
            postfix[p++]=token;
        }
        else if(token=='(')
        {
            push(&s,token);
        }
        else if(token==')')
        {
            while((x=pop(&s))!='(' && !isempty(&s))
            {
                postfix[++p]=x;
            }
        }
        else
        {
            while(precedence(token)<=precedence(peek(&s)) && !isempty(&s))
            {
                x=pop(&s);
                postfix[++p]=x;
            }
            push(&s,token);
        }  
    }
    while(!isempty(&s))
    {
        x=pop(&s);
        postfix[++p]=x;
    }
    postfix[++p]='\0';
}