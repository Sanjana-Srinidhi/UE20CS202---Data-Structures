#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct graph
{
    int a[max][max];
    int n;
} graph;

void init(graph *g, int n)
{
    g->n = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g->a[i][j] = 0;
        }
    }
}

graph *create(graph *g, int c[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        g->a[c[i][0]][c[i][1]] = 1;
        g->a[c[i][1]][c[i][0]] = 1;
    }
    return g;
}

void add_arc(graph *g, int v1, int v2)
{
    g->a[v1][v2] = 1;
}

void delete_arc(graph *g, int v1, int v2)
{
    g->a[v1][v2] = 0;
}

void arc_exists(graph *g, int v1, int v2)
{
    if (g->a[v1][v2] == 1)
    {
        printf("Arc exists\n");
    }
    else
    {
        printf("Arc does not exist\n");
    }
}

void display(graph *g, int n)
{
    printf("Adjacency Matrix\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", g->a[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    graph *g = (graph *)malloc(sizeof(graph));
    int a[][2] = {{0, 1}, {0, 3}, {0, 5}, {1, 2}, {1, 4}, {2, 3}, {3, 5}, {4, 5}};
    int n = 6;
    int e = 8;
    init(g, n);
    create(g, a, n);
    display(g, n);
    add_arc(g, 0, 4);
    display(g, n);
    delete_arc(g, 0, 4);
    display(g, n);
    arc_exists(g, 0, 3);
    arc_exists(g, 0, 4);
    return 0;
}