#include "PES2UG20CS549_H.h"
#include<stdlib.h>

int main()
{
    graph *g = (graph *)malloc(sizeof(graph));
    stack *s = (stack *)malloc(sizeof(stack));
    queue *q = (queue *)malloc(sizeof(queue));
    int n = rows();
    int startX;
    int startY;
    int endX;
    int endY;
    int exist = 0; //indicates if path exists, initially set to 0
    initGraph(g, n);
    initStack(s, n);
    initQueue(q, n);
    readMap(g, &startX, &startY, &endX, &endY);
    node *start = startNode(g, startX, startY);
    dfs(g, s, start, endX, endY, &exist);
    writePath(s, q, n, 1);
    exist = 0;
    bfs(g, q, start, endX, endY, &exist);
    writePath(s, q, n, 0);
    return 0;
}