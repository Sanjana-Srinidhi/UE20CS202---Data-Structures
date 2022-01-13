#include<stdio.h>
#include<stdlib.h>

typedef struct queue
{
    int *a;
    int front;
    int rear;
    int cap;
}queue;

void init(queue *q)
{
    q->front=-1;
    q->rear=-1;
    printf("Enter the capacity: ");
    scanf("%d",&q->cap);
    q->a=(int*)malloc(q->cap*sizeof(int));
}

int isfull(queue *q)
{
    if(q->rear==q->cap-1)
    {
        return -1;
    }
    return 0;
}

int isempty(queue *q)
{
    if(q->front==q->rear==-1)
    {
        return -1;
    }
    return 0;
}

void enqueue(queue *q, int ele)
{
    if(isfull(q)!=-1)
    {
        q->rear++;
        q->a[q->rear]=ele;
    }
    if(q->front==-1)
    {
        q->front++;
    }
}

void dequeue(queue *q)
{
    int ele;
    ele=q->a[q->front];
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
    }
    else if(!isempty(q))
    {
        q->front++;
    }
}

void display(queue *q)
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
    queue *q=(queue*)malloc(sizeof(queue));
    int c;
    int ele;
    init(q);
    while(1)
    {
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                printf("Enter the element to insert: ");
                scanf("%d",&ele);
                enqueue(q,ele);
                break;
            }
            case 2:
            {
                dequeue(q);
                break;
            }
            case 3:
            {
                display(q);
                break;
            }
            case 4:
            {
                exit(0);
            }
        }
    }
    return 0;
}