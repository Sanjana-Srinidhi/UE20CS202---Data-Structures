#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *rchild;
    struct node *lchild;
} node;

node *insert(node *root, int info)
{
    if (root == NULL)
    {
        root = (node *)malloc(sizeof(node));
        root->data = info;
        root->lchild = root->rchild = NULL;
    }
    else
    {
        if (info > root->data)
        {
            root->rchild = insert(root->rchild, info);
        }
        else
        {
            root->lchild = insert(root->lchild, info);
        }
    }
    return root;
}

void display(node *root)
{
    if (root != NULL)
    {
        display(root->lchild);
        printf("%d\t", root->data);
        display(root->rchild);
    }
}

void search(node *root, int d)
{
    if (root == NULL)
    {
        printf("%d not found in the tree\n", d);
    }
    else if (d == root->data)
    {
        printf("%d found in the tree\n", d);
    }
    else
    {
        if (d > root->data)
        {
            search(root->rchild, d);
        }
        else
        {
            search(root->lchild, d);
        }
    }
}

int count_node(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + count_node(root->lchild) + count_node(root->rchild);
    }
}

int count_leaf(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else if (root->lchild == NULL && root->rchild == NULL)
    {
        return 1;
    }
    else
    {
        return count_leaf(root->lchild) + count_leaf(root->rchild);
    }
}

int min(node *root)
{
    while (root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root->data;
}

int max(node *root)
{
    while (root->rchild != NULL)
    {
        root = root->rchild;
    }
    return root->data;
}

int height(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        int left = height(root->lchild);
        int right = height(root->rchild);
        return (left > right) ? (left + 1) : (right + 1);
    }
}

node *copy(node *root1, node *root2)
{
    if (root1)
    {
        root2 = insert(root2, root1->data);
        root2->lchild = copy(root1->lchild, root2->lchild);
        root2->rchild = copy(root1->rchild, root2->rchild);
    }
    return root2;
}

int compare(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return 1;
    }
    else if (root1 == NULL || root2 == NULL)
    {
        return 0;
    }
    else
    {
        return compare(root1->lchild, root2->lchild) && compare(root1->rchild, root2->rchild);
    }
}

node *mirror(node *root1, node *root2)
{
    if (root1 == NULL)
    {
        return root1;
    }
    else
    {
        root2 = insert(root2, root1->data);
        root2->lchild = mirror(root1->rchild, root2->lchild);
        root2->rchild = mirror(root1->lchild, root2->rchild);
    }
    return root2;
}

/**int *copy_arr(node *root, int *t, int i, int n)
{
    if(i<n)
    {
        t[i]=root->data;
        int l=2*i;
        int r=(2*i)+1;
        t=copy_arr(root->lchild,t,l,n);
        t=copy_arr(root->rchild,t,r,n);

    }
    return t;
}**/

void level_order(node *root, int i)
{
    if (i == 1)
    {
        printf("%d\t", root->data);
    }
    else
    {
        if (root->lchild != NULL)
        {
            level_order(root->lchild, i - 1);
        }
        if (root->rchild != NULL)
        {
            level_order(root->rchild, i - 1);
        }
    }
}

int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    root1 = insert(root1, 50);
    root1 = insert(root1, 100);
    root1 = insert(root1, 130);
    root1 = insert(root1, 20);
    root1 = insert(root1, 14);
    root1 = insert(root1, 140);
    printf("The tree contains:\t");
    display(root1);
    printf("\n");
    search(root1, 20);
    search(root1, 98);
    printf("Number of nodes in the tree: %d\n", count_node(root1));
    printf("Number of leaves in the tree: %d\n", count_leaf(root1));
    printf("Minimum element in the tree: %d\n", min(root1));
    printf("Maximum element in the tree: %d\n", max(root1));
    printf("Height of the tree: %d\n", height(root1));
    printf("After copying one tree into another tree:\t");
    root2 = copy(root1, root2);
    display(root2);
    printf("\n");
    int res = compare(root1, root2);
    if (res == 1)
    {
        printf("Both the trees are equal\n");
    }
    else
    {
        printf("Both the trees are unequal\n");
    }
    printf("Mirrored tree:\t");
    mirror(root1, root2);
    display(root2);
    printf("\n");
    int h = height(root1);
    printf("Level ordered insertion: ");
    for (int i = 1; i <= h; i++)
    {
        level_order(root1, i);
    }
    printf("\n");
    return 0;
}
