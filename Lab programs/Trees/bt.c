#include <stdio.h>
#include <stdlib.h>

void init(int *t, int n)
{
    for (int i = 0; i < n; i++)
    {
        t[i] = -1;
    }
}

int *insert(int *t, int data, int i, int n)
{
    if (t[i] == -1)
    {
        t[i] = data;
    }
    else
    {
        int l = 2 * i;
        int r = (2 * i) + 1;
        if (t[l] == -1)
        {
            t[l] = data;
        }
        else if (t[r] == -1)
        {
            t[r] = data;
        }
        else
        {
            if (l >= n)
            {
                t = insert(t, data, l / 2, n);
            }
            else if (r >= n)
            {
                t = insert(t, data, (r - 1) / 2, n);
            }
            else
            {
                if (l < n)
                {
                    t = insert(t, data, l, n);
                }
                else
                {
                    t = insert(t, data, r, n);
                }
            }
        }
    }
    return t;
}

void preorder(int *t, int i, int n)
{
    if (i < n)
    {
        printf("%d\t", t[i]);
        preorder(t, 2 * i, n);
        preorder(t, (2 * i) + 1, n);
    }
}

int bt(int *t, int i, int n)
{
    int l = 2 * i;
    int r = (2 * i) + 1;
    if (t[l] < t[i] && l < n)
    {
        bt(t, l, n);
    }
    else
    {
        return 0;
    }
    if (t[r] > t[i] && r < n)
    {
        bt(t, r, n);
    }
    else
    {
        return 0;
    }
    return 1;
}

int main()
{
    int n;
    int k;
    int data;
    printf("Enter the number of elemenets in the tree: ");
    scanf("%d", &k);
    n = k + 1;
    int *t = (int *)malloc(n * sizeof(int));
    init(t, n);
    for (int i = 0; i < k; i++)
    {
        printf("Enter the data to be inserted: ");
        scanf("%d", &data);
        t = insert(t, data, 1, n);
    }
    printf("The tree in preorder is: ");
    preorder(t, 1, n);
    printf("\n");
    int c = bt(t, 1, n);
    if (c == 1)
    {
        printf("The tree is a binary search tree");
    }
    else
    {
        printf("The tree is not a binary search tree");
    }
}