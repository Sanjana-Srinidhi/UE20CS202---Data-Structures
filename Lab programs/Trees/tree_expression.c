#include<stdio.h>
#include<stdlib.h>
#define max 100

typedef struct node
{
    char data;
    struct node *lchild;
    struct node *rchild;
}node;

typedef struct stack
{
    node *t[100];
    int top;
}stack;

void inits(stack *s)
{
    s->top=-1;
}

void push(stack *s, node *ch)
{
    s->top++;
    s->t[s->top]=ch;
}

node *pop(stack *s)
{
    node *ch=s->t[s->top];
    s->top--;
    return ch;
}

node *init(node *root, char ch)
{
    root=(node*)malloc(sizeof(node));
    root->data=ch;
    root->lchild=NULL;
    root->rchild=NULL;
    return root;
}

int isop(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        return 1;
    }
    return 0;
}

node *create(char *exp)
{
    node *root;
    stack *s=(stack*)malloc(sizeof(stack));
    inits(s);
    char ch=exp[0];
    int flag=1;
    while(ch!='\0')
    {
        root=(node*)malloc(sizeof(node));
        root=init(root,ch);
        if(isop(ch)==1)
        {
            root->rchild=pop(s);
            root->lchild=pop(s);
        }
        push(s,root);
        ch=exp[flag++];
    }
    node *x=pop(s);
    return x;
}

void inorder(node *root)
{
    if(root)
    {
        inorder(root->lchild);
        printf("%c", root->data);
        inorder(root->rchild);
    }
}

float evaluate(node *root)
{
    if (isop(root->data)==1)
    {
        float op1;
        float op2;
        op1 = evaluate(root->lchild);
        op2 = evaluate(root->rchild);
        switch(root->data)
        {
            case '+':
            {
                return op1 + op2;
            }
            case '-':
            {
                return op1 - op2;
            }
            case '*':
            {
                return op1 * op2;
            }
            case '/':
            {
                return op1 / op2;
            }
        }
    }
    else
    {
        float op;
        op=(root->data)-48;
        return op;
    }
}

int main()
{
    node *root = NULL;
    char exp[max];
    printf("Enter the expression: ");
    scanf("%s", exp);
    root=create(exp);
    inorder(root);
    printf("\n");
    printf("%.2f",evaluate(root));
    return 0;
}