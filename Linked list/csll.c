#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *link;
} node;

void create_node(node **tail, int ele)
{
    *tail = (node *)malloc(sizeof(node));
    (*tail)->data = ele;
    (*tail)->link = NULL;
}

void insert_start(node **tail, int ele)
{
    node *temp;
    create_node(&temp, ele);
    if (*tail == NULL)
    {
        *tail = temp;
        temp->link = *tail;
        //printf("%d\n", temp->data);
    }
    else
    {
        temp->link = (*tail)->link;
        (*tail)->link = temp;
        *tail = temp;
        //printf("%d\t%d\n", temp->link->data, (*tail)->data);
    }
}

void insert_end(node **tail, int ele)
{
    node *temp;
    create_node(&temp, ele);
    if (*tail != NULL)
    {
        temp->link = (*tail)->link;
        (*tail)->link = temp;
    }
    *tail = temp;
}

void insert_pos(node **tail, int ele, int pos)
{
    node *temp;
    create_node(&temp, ele);
    if (pos == 1 || *tail == NULL)
    {
        temp->link = (*tail)->link;
        (*tail)->link = temp;
    }
    else
    {
        int i = 1;
        node *dtail = (*tail)->link;
        while (dtail != *tail && i != pos - 1)
        {
            dtail = dtail->link;
            i++;
        }
        if (i == pos - 1)
        {
            if (dtail == *tail)
            {
                insert_end(tail, ele);
            }
            else
            {
                temp->link = dtail->link;
                dtail->link = temp;
            }
        }
        else
        {
            printf("Node not found :(\n");
        }
    }
}

void del_start(node **tail)
{
    if (*tail == NULL)
        printf("Empty List\n");
    else if ((*tail)->link == *tail)
    {
        free(*tail);
        *tail = NULL;
    }
    else
    {
        node *dtail = (*tail)->link;
        (*tail)->link = dtail->link;
        free(dtail);
        dtail = NULL;
    }
}

void del_end(node **tail)
{
    if (*tail == NULL)
        printf("Empty List\n");
    else if ((*tail)->link == *tail)
    {
        free(*tail);
        *tail = NULL;
    }
    else
    {
        node *dtail = (*tail)->link;
        while (dtail->link != *tail)
        {
            dtail = dtail->link;
        }
        dtail->link = dtail->link->link;
        free(*tail);
        *tail = dtail;
    }
}

void del_pos(node **tail, int pos)
{
    if (*tail == NULL)
    {
        printf("Empty List\n");
    }
    else if (pos == 1)
    {
        del_start(tail);
    }
    else
    {
        int i = 1;
        node *dtail = (*tail)->link;
        while (dtail->link != *tail && i != pos - 1)
        {
            dtail = dtail->link;
            i++;
        }
        if (i == pos - 1)
        {
            if (dtail->link == *tail)
            {
                del_end(tail);
            }
            else
            {
                node *del = dtail->link;
                dtail->link = dtail->link->link;
                free(del);
                del = NULL;
            }
        }
        else
        {
            printf("Node not found :(\n");
        }
    }
}

void display(node *tail)
{
    node *dstart = tail->link;
    do
    {
        printf("%d\t", dstart->data);
        dstart = dstart->link;
    } while (dstart != tail->link);
    printf("\n");
}

int main()
{
    node *tail = NULL;
    printf("-------CSLL using tail pointer-------\n\n");
    insert_start(&tail, 10);
    insert_start(&tail, 20);
    insert_start(&tail, 30);
    insert_start(&tail, 40);
    insert_start(&tail, 50);
    insert_end(&tail, 5);
    insert_end(&tail, 15);
    insert_end(&tail, 25);
    insert_end(&tail, 35);
    insert_end(&tail, 45);
    printf("Printing full list:\n");
    display(tail);
    insert_pos(&tail, 27, 11);
    printf("\nAdding 27 at position 11 and printing list:\n");
    display(tail);
    del_start(&tail);
    printf("\nDeleting from start:\n");
    display(tail);
    del_end(&tail);
    printf("\nDeleting from last:\n");
    display(tail);
    del_pos(&tail, 9);
    printf("\nDeleting from position 9:\n");
    display(tail);
    return 0;
}