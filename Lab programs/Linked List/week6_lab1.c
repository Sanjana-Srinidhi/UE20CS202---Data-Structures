#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *head=NULL;

void insert(int ele)
{
    node *new=(node*)malloc(sizeof(node));
    new->data=ele;
    if(head==NULL)
    {
        head=new;
        new->next=head; 
    }
    else
    {
        node *temp;
        temp=head;
        while(temp->next!=head)
        {
            temp=temp->next;
        }
        temp->next=new;
        new->next=head;
    }
}

void display()
{
    node *temp;
    temp=head;
    printf("The list contains: ");
    while(temp->next!=head)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("%d\n",temp->data);
}

void survivor(int k)
{
    struct node *p;
    struct node *q;
    p=q=head;
    while(p->next!=p)
    {
        for(int i=0;i<k;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        printf("%d has been killed\n",p->data);
        free(p);
        p=q->next;
    }
    head=p;
    printf("The last one to survive is %d\n",p->data);
}

int main()
{
    int n;
    int k;
    printf("Enter the number of people in the circle: ");
    scanf("%d",&n);
    printf("Enter the k value: ");
    scanf("%d",&k);
    for(int i=0;i<n;i++)
    {
        insert(i+1);
    }
    display();
    survivor(k-1);
    display();
    return 0;
}
