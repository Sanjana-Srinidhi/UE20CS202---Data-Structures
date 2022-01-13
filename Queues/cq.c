#include<stdio.h>
#include<stdlib.h>
#define max 5

typedef struct cq
{
    int a[max];
    int front;
    int rear;
}cq;

void init(cq *q)
{
    q->front=-1;
    q->rear=-1;
}

int isempty(cq *q)
{
    if(q->front==-1)
        return -1;
    return 0;
}

int isfull(cq *q)
{
    if(q->rear+1%max==q->front)
        return -1;
    return 0;
}

int insert(cq *q, int ele)
{
    if(isfull(q)==-1)
    {
        return -1;
    }
    else
    {
        q->rear=q->rear+1%max;
        q->a[q->rear]=ele;
        if(q->front==-1)
        {
            q->front=0;
        }
        return 0;
    }
}

int delete(cq *q)
{
    int ele;
    if(isempty(q)==-1)
    {
        return -1;
    }
    else
    {
        ele=q->a[q->front];
        if(q->front==q->rear)
        {
            q->front=q->rear=-1;
        }
        else
        {
            q->front=q->front+1%max;
        }
    }
}

void display(cq *q)
{
    while(q->front!=q->rear)
    {
        printf("%d\t",q->a[q->front]);
        q->front=q->front+1%max;
    }
    printf("%d\n",q->a[q->front]);
}

int main()
{
    cq q;
    init(&q);
    insert(&q,10);
    insert(&q,20);
    insert(&q,30);
    insert(&q,40);
    insert(&q,50);
    delete(&q);
    delete(&q);
    display(&q);
    return 0;
}