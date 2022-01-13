#include <stdio.h>
#include <stdlib.h>

typedef struct n
{
    int data;
    struct n *link;
} node;

void create_node(node **temp, int ele)
{
    *temp = (node *)malloc(sizeof(node));
    (*temp)->link = NULL;
    (*temp)->data = ele;
}

int return_pos(node *head, int ele)
{
    int f = 1;
    while (head != NULL)
    {
        if (head->data < ele)
        {
            head = head->link;
            f++;
        }
        else
        {
            break;
        }
    }
    return f;
}

void insert_pos(node **head, int ele, int pos)
{
    node *temp;
    create_node(&temp, ele);
    if (pos == 1)
    {
        temp->link = (*head);
        *head = temp;
    }
    else
    {
        int f = 1;
        node *dstart = *head;
        while (f != pos - 1 && dstart->link != NULL)
        {
            f++;
            dstart = dstart->link;
        }
        temp->link = dstart->link;
        dstart->link = temp;
    }
}

void display(const node *head)
{
    while (head != NULL)
    {
        printf("%d\t", head->data);
        head = head->link;
    }
    printf("\n");
}

void order(node **head)
{
    int ele;
    printf("Enter the element: ");
    scanf("%d", &ele);
    int pos = return_pos((*head), ele);
    insert_pos(head, ele, pos);
}

int main()
{
    node *head = NULL;
    int choice;
    while (1 != 0)
    {
        printf("Enter:\n1. To add an element\n2. To display\n3. To exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            order(&head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Input\n");
        }
    }
    return 0;
}