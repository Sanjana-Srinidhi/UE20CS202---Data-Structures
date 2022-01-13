#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *llink;
    struct n *rlink;
} node;

void create_node(node **head, int ele)
{
    *head = (node *)malloc(sizeof(node));
    (*head)->data = ele;
    (*head)->llink = NULL;
    (*head)->rlink = NULL;
}

void insert_start(node **head, int ele)
{
    node *temp;
    create_node(&temp, ele);
    if (*head != NULL)
    {
        (*head)->llink = temp;
        temp->rlink = (*head);
    }
    *head = temp;
}

void insert_end(node **head, int ele)
{
    node *temp;
    create_node(&temp, ele);
    if (*head == NULL)
    {
        *head = temp;
    }
    else
    {
        node *dstart = *head;
        while (dstart->rlink != NULL)
        {
            dstart = dstart->rlink;
        }
        temp->llink = dstart;
        dstart->rlink = temp;
    }
}

void insert_pos(node **head, int ele, int pos)
{
    node *temp;
    create_node(&temp, ele);
    if (*head == NULL || pos == 1)
        insert_start(head, ele);
    else
    {
        int i = 1;
        node *dstart = *head;
        while (dstart->rlink != NULL && i != pos - 1)
        {
            dstart = dstart->rlink;
            i++;
        }
        if (i == pos - 1)
        {
            if (dstart->rlink == NULL)
                insert_end(head, ele);
            else
            {
                temp->llink = dstart;
                temp->rlink = dstart->rlink;
                temp->rlink->llink = temp;
                dstart->rlink = temp;
            }
        }
        else
        {
            printf("Node not found :(\n");
        }
    }
}

void del_start(node **head)
{
    if (*head == NULL)
    {
        printf("List Empty\n");
    }
    else
    {
        node *temp = *head;
        *head = (*head)->rlink;
        free(temp);
        (*head)->llink = NULL;
    }
}

void del_end(node **head)
{
    if (*head == NULL)
    {
        printf("Empty List\n");
    }
    else
    {
        node *dstart = *head;
        while (dstart->rlink != NULL)
        {
            dstart = dstart->rlink;
        }
        dstart->llink->rlink = NULL;
        free(dstart);
    }
}

void del_pos(node **head, int pos)
{
    if (*head == NULL)
    {
        printf("Empty List\n");
    }
    else if (pos == 1)
    {
        del_start(head);
    }
    else
    {
        node *dstart = *head;
        int i = 0;
        while (dstart->rlink != NULL && i != pos - 1)
        {
            dstart = dstart->rlink;
            i++;
        }
        if (i == pos - 1)
        {
            if (dstart->rlink == NULL)
                del_end(head);
            else
            {
                dstart->rlink->llink = dstart->llink;
                dstart->llink->rlink = dstart->rlink;
                free(dstart);
            }
        }
        else
        {
            printf("Node not found :(\n");
        }
    }
}

node *Reverse(node *Node)
{
    // If empty list, return
    if (!Node)
        return NULL;

    // Otherwise, swap the llink and rlink
    node *temp = Node->rlink;
    Node->rlink = Node->llink;
    Node->llink = temp;

    // If the llink is now NULL, the list has been fully reversed
    if (!Node->llink)
        return Node;

    // Otherwise, keep going
    return Reverse(Node->llink);
}

void display(const node *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->rlink;
    }
    printf("\n");
}

int main()
{
    node *head = NULL;
    insert_start(&head, 10);
    insert_start(&head, 20);
    insert_start(&head, 30);
    insert_start(&head, 40);
    insert_start(&head, 50);
    insert_end(&head, 5);
    insert_end(&head, 15);
    insert_end(&head, 25);
    insert_end(&head, 35);
    insert_end(&head, 45);
    printf("Printing full list:\n");
    display(head);
    node *temp = Reverse(head);
    display(temp);
    return 0;
}