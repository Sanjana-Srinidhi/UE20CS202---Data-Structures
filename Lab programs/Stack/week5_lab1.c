#include<stdio.h>
#include<stdlib.h>

typedef struct stack
{
    int *a;
    int top1;
    int top2;
    int cap;
}stack;

void init(stack *s);
int isfull(stack *s);
int isempty(stack *s);
void push(stack *s, int ele, int c);
void pop(stack *s, int c);

void init(stack *s)
{
    s->top1=-1;
    printf("Enter the capacity: ");
    scanf("%d",&s->cap);
    s->top2=s->cap;
    s->a=(int*)malloc(s->cap*sizeof(int));
}

int isfull(stack *s)
{
    if(s->top1==s->top2-1)
    {
        return -1;
    }
    else
        return 0;
}

int isempty(stack *s)
{
    if(s->top1==-1)
    {
        return -1;
    }
    else if(s->top2==s->cap)
    {
        return -2;
    }
    else 
        return 0;
}

void push(stack *s, int ele, int c)
{
    if(!isfull(s))
    {
        if(c==1)
        {
            s->top1++;
            s->a[s->top1]=ele;
        }
        else if(c==2)
        {
            s->top2--;
            s->a[s->top2]=ele;
        }
    }
}

void pop(stack *s, int c)
{
    int ele;
    if(!isempty(s))
    {
        if(c==1)
        {   
            ele=s->a[s->top1];
            s->top1--;   
        }
        else if(c==2)
        {
            ele=s->a[s->top2];
            s->top2++; 
        }
    }
}

void display(stack *s)
{
    int f1=0;
    printf("Stack 1\n");
    while(f1<=s->top1)
    {
        printf("%d\t",s->a[f1]);
        f1++;
    }   
    printf("\n");
    printf("Stack 2\n"); 
    int f2=s->cap-1;
    while(f2>=s->top2)
    {
        printf("%d\t",s->a[f2]);
        f2--;
    }   
    printf("\n");
}

int main()
{
    int c;
    stack *s=(stack*)malloc(sizeof(stack));
    init(s);
    int ch;
    int ele;
    while(1)
    {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                printf("Enter 1 to insert into the first stack and 2 to insert into the second stack: ");
                scanf("%d",&c);
                printf("Enter the element to be inserted: ");
                scanf("%d",&ele);
                push(s,ele,c);
                break;
            }
            case 2:
            {
                printf("Enter 1 to delete from the first stack and 2 to delete from the second stack: ");
                scanf("%d",&c);
                pop(s,c);
                break;
            }
            case 3:
            {
                display(s);
                break;
            }
            case 4:
            {
                exit(0);
            }
        }
    }
}
