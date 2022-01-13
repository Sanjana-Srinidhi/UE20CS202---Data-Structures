// Graph traversal using DFS
#include <stdio.h>
#include <stdlib.h>
#define MAX 3

int **createMat(int n)
{
    int adjmat[MAX][MAX];
}

void dfs(int src, int adjmat[MAX][MAX], int *visited, int n, int flag)
{
    visited[src] = 1;
    if (flag == 1)
        printf("%d\t", src);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        if (adjmat[src][i] == 1 && visited[i] == 0)
        {
            dfs(i, adjmat, visited, n, flag);
        }
    }
}

void DFS(int src, int adjmat[MAX][MAX], int *visited, int n, int count)
{
    dfs(src, adjmat, visited, n, 1);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i, adjmat, visited, n, 1);
            count++;
        }
    }
    printf("\nNumber of components: %d\n", count);
}

void check_connect(int start, int adjmat[MAX][MAX], int visited[MAX], int n, int dest)
{
    dfs(start, adjmat, visited, n, 0);
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[dest] == 1)
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("%d is connected to %d\n", start, dest);
    }
    else
    {
        printf("%d is not connected to %d\n", start, dest);
    }
}

void init_v(int visited[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        visited[i] = 0;
    }
}

int main()
{
    int visited[MAX];
    int choice, dest;
    int adjmat[MAX][MAX]; 
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            printf("Enter choice: ");
            scanf("%d", &choice);
            adjmat[i][j] = choice;
        }
    }
    while (1 != 0)
    {
        printf("Enter\n1. DFS traversal\n2.Checking connectivity of graph\n3.exit\n->");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            init_v(visited);
            printf("Enter the source: ");
            scanf("%d", &choice);
            DFS(choice, adjmat, visited, MAX, 1);
            break;
        case 2:
            init_v(visited);
            printf("Enter the source: ");
            scanf("%d", &choice);
            printf("Enter the destination: ");
            scanf("%d", &dest);
            check_connect(choice, adjmat, visited, MAX, dest);
            break;

        case 3:
            exit(0);
        }
    }
    return 0;
}