#include <stdio.h>
#include <stdlib.h>

struct n
{
    int data;
    struct n *link;
};
typedef struct n node;

void insert_start(node **head, int ele)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ele;
    temp->link = NULL;
    if (*head != NULL)
        temp->link = *head;
    *head = temp;
}

node *insert_end(node *head, int ele)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ele;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        node *dstart = head;
        while (dstart->link != NULL)
        {
            dstart = dstart->link;
        }
        dstart->link = temp;
    }
    return head;
}

void reverse(node **head)
{
    node *pres, *next;
    //printf("Here atleast\n");
    if (*head != NULL || (*head)->link != NULL)
    {
        pres = (*head)->link;
        next = pres->link;
        (*head)->link = NULL;
        while (next != NULL)
        {
            //printf("%d\t%d\t%d\n", (*head)->data, pres->data, next->data);
            pres->link = *head;
            *head = pres;
            pres = next;
            next = next->link;
        }
        pres->link = *head;
        *head = pres;
        //printf("%d\n", (*head)->link->link->link->link->data);
    }
}

node *merge(node *st1, node *st2)
{
    node *temp = NULL;
    while (st1 != NULL || st2 != NULL)
    {
        if (st1 == NULL)
        {
            temp = insert_end(temp, st2->data);
            st2 = st2->link;
        }
        else if (st2 == NULL)
        {
            temp = insert_end(temp, st1->data);
            st1 = st1->link;
        }
        else
        {
            if (st1->data < st2->data)
            {
                temp = insert_end(temp, st1->data);
                st1 = st1->link;
            }
            else
            {
                temp = insert_end(temp, st2->data);
                st2 = st2->link;
            }
        }
    }
    return temp;
}

void display(const node *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->link;
    }
}

int main()
{
    node *head = NULL, *head2 = NULL;
    insert_start(&head, 55);
    insert_start(&head, 45);
    insert_start(&head, 35);
    head = insert_end(head, 65);
    head2 = insert_end(head2, 10);
    head2 = insert_end(head2, 20);
    head2 = insert_end(head2, 40);
    reverse(&head);
    display(head);
    //node *merge1 = merge(head2, head);
    //display(head);
    //display(merge1);
}