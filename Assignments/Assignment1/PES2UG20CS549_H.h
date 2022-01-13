#ifndef DSA_H
#define DSA_H

typedef struct node
{
    int x;
    int y;
    struct node *top;
    struct node *down;
    struct node *left;
    struct node *right;
} node;

typedef struct queue
{
    node *data;
    struct queue *link;
} queue;

typedef struct header
{
    node *start;
    struct header *right;
    struct header *down;
} header;

queue *init_queue(node *temp);
header *init_header();
node *init_node(int x, int y);
void enqueue(queue **head, node *data);
node *dequeue(queue **head);
node *delete_end_queue(queue **head);
header *create_header(int *end_x, int *end_y);
header *link(header *head, int i, int j);
header *readMap(int *start_x, int *start_y, int *end_x, int *end_y);
queue *findPath(header *head, int start_x, int start_y, int end_x, int end_y);
int storePath(header *head, int start_x, int start_y, int end_x, int end_y);

#endif