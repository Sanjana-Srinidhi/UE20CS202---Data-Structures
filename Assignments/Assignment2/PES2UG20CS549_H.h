#ifndef DSA_H
#define DSA_H

typedef struct coordinates
{
    int x;
    int y;
} coordinates;

typedef struct node
{
    int vid;
    int rowno;
    int columnno;
    struct node *link;
} node;

typedef struct graph
{
    int n;
    node **a;
} graph;

typedef struct stack
{
    coordinates *x;
    int top;
} stack;

typedef struct queue
{
    coordinates *y;
    int front;
    int rear;
} queue;

node *initList(node *temp, int id, int i, int j);
void initGraph(graph *g, int n);
void initStack(stack *s, int n);
void initQueue(queue *q, int n);
void push(stack *s, coordinates data);
coordinates pop(stack *s);
int isStackEmpty(stack *s);
void enqueue(queue *q, coordinates data);
coordinates dequeue(queue *q);
coordinates dequeueEnd(queue *q);
int isQueueEmpty(queue *q);
int rows();
node *startNode(graph *g, int i, int j);
void createList(graph *g, int matrix[100][100]);
void readMap(graph *g, int *startX, int *startY, int *endX, int *endY);
node *findPath(graph *g, node *temp1, int flag);
void dfs(graph *g, stack *s, node *temp1, int endX, int endY, int *exist);
void bfs(graph *g, queue *q, node *temp1, int endX, int endY, int *exist);
void writePath(stack *s, queue *q, int n, int flag);

#endif