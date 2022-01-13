#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct queue
{
    int *a;
    int front;
    int rear;
} queue;

void initQueue(queue *q, int n)
{
    q->a = (int *)malloc(sizeof(int) * n);
    q->front = q->rear = -1;
}

void enqueue(queue *q, int v)
{
    q->rear++;
    q->a[q->rear] = v;
}

int dequeue(queue *q)
{
    return q->a[q->front++];
}

int isEmpty(queue *q)
{
    if (q->front - q->rear == 1)
    {
        return -1;
    }
    return 0;
}

void initArray(int *visited, int n)
{
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
}

void bfs(int ad[max][max], int v, int *visited, int n, queue *q)
{
    visited[v] = 1;
    enqueue(q, v);
    printf("%d\n", v);
    for (int i = 0; i < n; i++)
    {
        if (ad[v][i] == 1 && visited[i] == 0)
        {
            visited[i] = 1;
            enqueue(q, i);
        }
    }
}

void BFS(int ad[max][max], int v, int *visited, int n, queue *q)
{
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            bfs(ad, i, visited, n, q);
        }
    }
    printf("\n");
}

int main()
{
    queue *q;
    q = (queue *)malloc(sizeof(queue));
    int visited[max];
    int ad[max][max];
    int n;
    int c;
    printf("Enter the size of the adjacency matrix: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter 1 if %d and %d are conncted, else 0: ", i, j);
            scanf("%d", &c);
            ad[i][j] = 0;
        }
    }
    initQueue(q, n);
    initArray(visited, n);
    BFS(ad, 0, visited, n, q);
    initArray(visited, n);
    return 0;
}