#include "PES2UG20CS549_H.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

queue *init_queue(node *temp)
{
    queue *q = (queue *)malloc(sizeof(queue));
    q->data = temp;
    q->link = NULL;
    return q;
}

header *init_header()
{
    header *head = (header *)malloc(sizeof(node));
    head->start = NULL;
    head->right = head->down = NULL;
    return head;
}

node *init_node(int x, int y)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->x = x;
    temp->y = y;
    temp->down = temp->left = temp->right = temp->top = NULL;
    return temp;
}

void enqueue(queue **head, node *data)
{
    queue *q = init_queue(data);
    if (*head == NULL)
    {
        *head = q;
    }
    else
    {
        queue *temp = *head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = q;
    }
}

node *dequeue(queue **head)
{
    queue *temp = *head;
    if (*head == NULL)
    {
        return NULL;
    }
    else
    {
        *head = (*head)->link;
        return temp->data;
    }
}

node *delete_end_queue(queue **head)
{
    queue *temp = *head;
    queue *prev = NULL;
    while(temp != NULL)
    {
        prev = temp;
        temp = temp->link;
    }
    free(temp);
    prev->link = NULL;
    return prev->data;
}

header *create_header(int *end_x, int *end_y)
{
    header *head = init_header();
    head->right = init_header();
    head->down = init_header();
    header *hdown = head->down;
    header *hright = head->right;
    header *temp_right = NULL;
    header *temp_down = NULL;
    
    for (int i = 0; i < *end_y; i++)
    {
        temp_right = init_header();
        hright->right = temp_right;
        hright = hright->right;
    }
    for (int j = 0; j < *end_x; j++)
    {
        temp_down = init_header();
        hdown->down = temp_down;
        hdown = hdown->down;
    }
    return head;
}

header *link(header *head, int i, int j)
{
    node *temp = init_node(i, j);
    node *d_tmp = NULL;
    header *hright = head->right;
    header *hdown = head->down;
    for (int k = 0; k < j; k++)
    {
        hright = hright->right;
    }
    if (hright->start == NULL)
    {
        hright->start = temp;
    }
    else
    {
        d_tmp = hright->start;
        while (d_tmp->down != NULL)
        {
            d_tmp = d_tmp->down;
        }
        d_tmp->down = temp;
        temp->top = d_tmp;
    }

    for (int k = 0; k < i; k++)
    {
        hdown = hdown->down;
    }
    if (hdown->start == NULL)
    {
        hdown->start = temp;
    }
    else
    {
        d_tmp = hdown->start;
        while (d_tmp->right != NULL)
        {
            d_tmp = d_tmp->right;
        }
        d_tmp->right = temp;
        temp->left = d_tmp;
    }
    return head;
}

header *readMap(int *start_x, int *start_y, int *end_x, int* end_y)
{
    FILE *fr;
    header *map = NULL;
    int i = 0;
    int j = 0;
    char start[10];
    char end[10];
    char str[100];
    fr = fopen("input.txt", "r");
    fgets(start, 6, fr);
    fgets(end, 6, fr);
    *start_x = start[0] - 48;
    *start_y = start[2] - 48;
    *end_x = end[0] - 48;
    *end_y = end[2] - 48;
    map = create_header(end_x, end_y);
    while (fgets(str, 100, fr) != NULL)
    {
        for (j = 0; j < strlen(str); j++)
        {
            if (str[j] == '0')
            {
                map = link(map, i, j / 2);
            }
        }
        i++;
    }
    fclose(fr);
    return map;
}

queue *findPath(header *head, int start_x, int start_y, int end_x, int end_y)
{
    node *temp = head->start;
    queue *q = NULL;
    while ((temp->x == 0 && temp->y == 0) || temp->left != NULL || temp->top != NULL || (temp->x == 0 && temp->y == 0))
    {
        if (temp->x == end_x && temp->y == end_y)
        {
            enqueue(&q, temp);
            printf("Route map written onto the file 'PES2UG20CS549_out.txt'\n");
            return q;
        }
        else if (temp->right != NULL && temp->right->y <= end_y && (temp->y - temp->right->y) == -1)
        {
            enqueue(&q, temp);
            temp = temp->right;
        }
        else if (temp->down != NULL && temp->down->x <= end_x && (temp->x - temp->down->x) == -1)
        {
            enqueue(&q, temp);
            temp = temp->down;
        }
        else if ((temp->right == NULL || temp->down == NULL) || (temp->down->x - temp->x) > 1 && (temp->right->y - temp->y) > 1)
        {
            if ((temp->left)->y != (temp->y) - 1)
            {
                temp = temp->top->right;
                delete_end_queue(&q);
            }
            else
            {
                temp = temp->left->down;
                delete_end_queue(&q);
            }
        }
    }
    return NULL;
}

int storePath(header *head, int start_x, int start_y, int end_x, int end_y)
{
    queue *q;
    FILE *fw = fopen("PES2UG20CS549_out.txt", "w");
    q = findPath(head, start_x, start_y, end_x, end_y);
    if (q == NULL)
    {
        printf("No path found\n");
        fclose(fw);
        return -1;
    }
    node *temp = dequeue(&q);
    while (temp != NULL)
    {
        printf("%d %d\n", temp->x, temp->y); 
        fprintf(fw, "%d %d\n", temp->x, temp->y); 
        temp = dequeue(&q);
    }
    fclose(fw);
}
