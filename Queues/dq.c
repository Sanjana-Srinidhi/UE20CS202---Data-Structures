#include<stdio.h>
#include<stdlib.h>
#define max 10

typedef struct dq
{
    int a[max];
    int front;
    int rear;
}dq;

void init(dq *q)
{
    q->front=-1;
    q->rear=-1;
}

void insertbeg(dq *q, int ele)
{ 
    if(q->front==-1)
    {
        q->front=q->rear=0;
        q->a[0]=ele;
    }
    else if(q->front==0)
    {
        q->front=max-1;
    }
    else
    {
        q->front--;
        q->a[q->front]=ele;
    }
}

void insertend(dq *q, int ele)
{
    if(q->rear==max-1)
    {
        printf("overflow\n");
    }
    else
    {
        q->rear++;
        q->a[q->rear]=ele;
        if(q->front==-1)
        {
            q->front=0;
        }
    }
}

void deletebeg(dq *q)
{
    if(q->front==-1)
    {
        printf("underflow\n");
    }
    else
    {
        int ele;
        ele=q->a[q->front];   
        if(q->front==q->rear)
        {
            q->front=q->rear=-1;
        }
        else if(q->front==max-1)
        {
            q->front=0;
        }
        else
        {
            q->front++;
        }
    }
}

void deleteend(dq *q)
{
    if(q->front==-1)
    {
        printf("underflow");
    }
    else if(q->front==q->rear)
    {
        q->front=q->rear=-1;
    }
    else if(q->rear==0)
    {
        q->rear=max-1;
    }
    else
    {
        q->rear--;
    }
}

void display(dq *q)
{
    int i;
    for(i=q->front;i<=q->rear;i++)
    {
        printf("%d\t",q->a[i]);
    }
    printf("\n");
}

int main()
{
    dq q;
    init(&q);
    insertbeg(&q,10);
    insertbeg(&q,20);
    insertend(&q,30);
    insertend(&q,40);
    display(&q);
    deletebeg(&q);
    deleteend(&q);
    display(&q);
    return 0;
}