#include <stdio.h>
#include <stdlib.h>
#define max 6

void init_v(int *visited)
{
    for (int i = 0; i < max; i++)
    {
        visited[i] = 0;
    }
}

void dfs(int a[max][max], int v, int *visited, int n)
{
    visited[v] = 1;
    printf("%d\t", v);
    for (int i = 0; i < n; i++)      // v = 0 ; i = 
    {
        if (a[v][i] == 1 && visited[i] == 0)
        {
            dfs(a, i, visited, n);
        }
    }
}

void DFS(int a[max][max], int v, int *visited, int n, int component)
{
    dfs(a, v, visited, n);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(a, i, visited, n);
            component++;
        }
    }
    printf("\n");
    printf("Number of components through DFS: %d\n", component);
}

void connectivity(int a[max][max], int v, int *visited, int n)
{
    dfs(a, v, visited, n);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            printf("Disconnected graph\n");
            break;
        }
    }
    printf("\n");
    printf("Connected graph\n");
}

int main()
{
    int visited[max];
    int a[max][max] = {{0, 1, 1, 1, 0, 0}, {1, 0, 1, 1, 0, 1}, {1, 1, 0, 0, 0, 1}, {1, 1, 0, 0, 1, 0}, {0, 1, 1, 0, 1, 0}, {0, 0, 1, 1, 0, 1}};
    init_v(visited);
    DFS(a, 0, visited, max, 0);
    init_v(visited);
    connectivity(a, 0, visited, max);
    return 0;
}