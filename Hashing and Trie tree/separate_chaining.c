#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int key;
    struct node *next;
} node;

typedef struct hash
{
    node *a;
    int count;
} hash;

void init(hash *head)
{
    for (int i = 0; i < 10; i++)
    {
        head[i].a = NULL;
        head[i].count = 0;
    }
}

node *getnode(int key)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

void insert(hash *head, int key)
{
    node *temp;
    temp = getnode(key);
    int index;
    index = key % 10; // hash function
    if ((head[index]).a == NULL)
    {
        head[index].a = temp;
    }
    else
    {
        temp->next = head[index].a;
        head[index].a = temp;
    }
    head[index].count++;
}

void display(hash *head)
{
    for (int i = 0; i < 10; i++)
    {
        node *temp = head[i].a;
        while (temp != NULL)
        {
            printf("%d\t", temp->key);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    hash *head = (hash*)malloc(sizeof(hash)*10);
    init(head);
    insert(head, 5);
    insert(head, 7);
    insert(head, 9);
    insert(head, 15);
    insert(head, 17);
    display(head);
    return 0;
}