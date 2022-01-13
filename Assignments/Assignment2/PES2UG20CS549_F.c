#include "PES2UG20CS549_H.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node *initList(node *temp, int id, int i, int j)
{
    temp = (node *)malloc(sizeof(node));
    temp->vid = id;
    temp->rowno = i;
    temp->columnno = j;
    temp->link = NULL;
    return temp;
}

void initGraph(graph *g, int n)
{
    g->n = n;
    g->a = (node **)malloc((n + 1) * sizeof(node *));
    for (int i = 0; i <= n; i++)
    {
        g->a[i] = NULL;
    }
}

void initStack(stack *s, int n)
{
    s->x = (coordinates *)malloc((n + 1) * sizeof(coordinates));
    s->top = -1;
}

void initQueue(queue *q, int n)
{
    q->y = (coordinates *)malloc((n + 1) * sizeof(coordinates));
    q->front = -1;
    q->rear = -1;
}

void push(stack *s, coordinates data)
{
    s->top++;
    s->x[s->top] = data;
}

coordinates pop(stack *s)
{
    return s->x[s->top--];
}

int isStackEmpty(stack *s)
{
    if (s->top == -1)
    {
        return -1;
    }
    return 1;
}

void enqueue(queue *q, coordinates data)
{
    q->y[++(q->rear)] = data;
    if (q->front == -1)
    {
        q->front++;
    }
}

coordinates dequeue(queue *q)
{
    return q->y[q->front++];
}

coordinates dequeueEnd(queue *q)
{
    return q->y[q->rear--];
}

int isQueueEmpty(queue *q)
{
    if (q->front - q->rear == 1)
    {
        return -1;
    }
    return 1;
}

int rows() // return number of rows in the adjacency matrix read from the file
{
    FILE *fs = fopen("input.txt", "r");
    char str[100];
    int i = 0;
    while (fgets(str, 100, fs) != NULL)
    {
        i++;
    }
    fclose(fs);
    return i - 3;
}

node *startNode(graph *g, int i, int j) // returns the source node for traversal
{
    node *temp = g->a[i];
    while (temp != NULL && temp->columnno != j)
    {
        temp = temp->link;
    }
    return temp;
}

void createList(graph *g, int matrix[100][100]) // creating an adjacency list from the adjacency matrix
{
    int vid = 1; // row-wise vid numbering
    for (int i = 0; i <= g->n; i++)
    {
        for (int j = 0; j <= g->n; j++)
        {
            if (matrix[i][j] == 0)
            {
                node *temp = initList(temp, vid, i, j);
                if (g->a[i] == NULL)
                {
                    g->a[i] = temp;
                }
                else
                {
                    temp->link = g->a[i]; // insetion at the front of the list
                    g->a[i] = temp;
                }
                vid++;
            }
        }
    }
}

void readMap(graph *g, int *startX, int *startY, int *endX, int *endY) // reading the input file as an adjacency matrix
{
    char start[10];
    char end[10];
    char str[100];
    int matrix[100][100];
    int i = 0;
    FILE *fs = fopen("input.txt", "r");
    fgets(start, 6, fs);
    fgets(end, 6, fs);
    *startX = start[0] - 48; // source x-coordinate
    *startY = start[2] - 48; // source y-coordinate
    *endX = end[0] - 48;     // destination x-coordinate
    *endY = end[2] - 48;     // destination y-coordinate
    while (fgets(str, 100, fs) != NULL)
    {
        for (int j = 0; j < strlen(str); j += 2)
        {
            if (str[j] == '0' || str[j] == '1')
            {
                matrix[i][j / 2] = str[j] - 48;
            }
        }
        i++;
    }
    fclose(fs);
    createList(g, matrix);
}

node *findPath(graph *g, node *temp1, int flag)
{
    node *temp2;
    if (flag == 1) // returns the next node to the dfs function if it exists
    {
        if (temp1->rowno < g->n)
        {
            temp2 = g->a[temp1->rowno + 1];
            while (temp2)
            {
                if (temp2->columnno == temp1->columnno)
                {
                    return temp2;
                }
                temp2 = temp2->link;
            }
            return NULL;
        }
    }
    else // returns the next node to the bfs function if it exists
    {
        temp2 = g->a[temp1->rowno];
        while (temp2)
        {
            if (temp2->columnno == temp1->columnno + 1)
            {
                return temp2;
            }
            temp2 = temp2->link;
        }
        return NULL;
    }
}

void dfs(graph *g, stack *s, node *temp1, int endX, int endY, int *exist)
{
    coordinates current;
    current.x = temp1->rowno;
    current.y = temp1->columnno;
    push(s, current);
    if (temp1->columnno == endY && temp1->rowno == endX)
    {
        *exist = 1;
    }
    else
    {
        node *temp2;
        if (*exist != 1)
        {
            temp2 = findPath(g, temp1, 1);
            if (temp2)
            {
                dfs(g, s, temp2, endX, endY, exist);
            }
        }
        if (*exist != 1)
        {
            temp2 = findPath(g, temp1, 0);
            if (temp2)
            {
                dfs(g, s, temp2, endX, endY, exist);
            }
        }
        if (*exist != 1)
        {
            pop(s); // backtracking
        }
    }
}

void bfs(graph *g, queue *q, node *temp1, int endX, int endY, int *exist)
{
    coordinates current;
    current.x = temp1->rowno;
    current.y = temp1->columnno;
    enqueue(q, current);
    if (temp1->columnno == endY && temp1->rowno == endX)
    {
        *exist = 1;
    }
    else
    {
        node *temp2;
        if (*exist != 1)
        {
            temp2 = findPath(g, temp1, 0);
            if (temp2)
            {
                bfs(g, q, temp2, endX, endY, exist);
            }
        }
        if (*exist != 1)
        {
            temp2 = findPath(g, temp1, 1);
            if (temp2)
            {
                bfs(g, q, temp2, endX, endY, exist);
            }
        }
        if (*exist != 1)
        {
            dequeueEnd(q); // backtracking
        }
    }
}

void writePath(stack *s, queue *q, int n, int flag)
{
    coordinates dfsPath[100];
    coordinates v;
    if (flag == 1) //flag = 1 indicates path through dfs
    {
        FILE *fdfs = fopen("PES2UG20CS549_dfsout.txt", "w");
        if (isStackEmpty(s) == -1)
        {
            printf("No path found through DFS\n");
            fprintf(fdfs, "%d\n", -1);
        }
        else
        {

            int i = 0;
            while (isStackEmpty(s) != -1)
            {
                dfsPath[i] = pop(s);
                i++;
            }
            printf("Output of DFS:\n");
            for (int j = i - 1; j >= 0; j--)
            {
                printf("%d\t%d\n", dfsPath[j].x, dfsPath[j].y);
                fprintf(fdfs, "%d\t%d\n", dfsPath[j].x, dfsPath[j].y);
            }
        }
        fclose(fdfs);
    }

    else 
    {
        FILE *fbfs = fopen("PES2UG20CS549_bfsout.txt", "w");
        if (isQueueEmpty(q) == -1)
        {
            printf("No path found through BFS\n");
            fprintf(fbfs, "%d\n", -1);
        }
        else
        {
            printf("Output of BFS:\n");
            while (isQueueEmpty(q) != -1)
            {
                v = dequeue(q);
                printf("%d\t%d\n", v.x, v.y);
                fprintf(fbfs, "%d\t%d\n", v.x, v.y);
            }
        }
        fclose(fbfs);
    }
}
