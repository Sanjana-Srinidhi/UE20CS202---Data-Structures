#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *link;
} node;

void reverse(node **head)
{
    node *pres, *next;
    if (*head != NULL && (*head)->link != NULL)
    {

        pres = (*head)->link;
        next = pres->link;
        while (next != NULL)
        {
            pres->link = *head;
            *head = pres;
            pres = next;
            next = next->link;
        }
        pres->link = *head;
    }
}
