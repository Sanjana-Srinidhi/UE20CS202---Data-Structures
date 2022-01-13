#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
    char *data;
    struct node *rchild;
    struct node *lchild;
}node;

node *insert(node *root, char *srn)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));
        root->data=srn;
        root->rchild=NULL;
        root->lchild=NULL;
    }
    else
    {
        if(strcmp(srn,root->data)>0)
        {
            root->rchild=insert(root->rchild,srn);
        }
        else
        {
            root->lchild=insert(root->lchild,srn);
        }
    }
    return root;
}

void search(node *root, char *srn)
{
    if(root==NULL)
    {
        printf("%s not found\n",srn);
    }
    else if(strcmp(srn,root->data)==0)
    {
        printf("%s found\n",srn);
    }
    else
    {
        if(strcmp(srn,root->data)>0)
        {
            search(root->rchild,srn);
        }
        else
        {
            search(root->lchild,srn);
        }
    }
}

void display(node *root)
{
    if(root!=NULL)
    {
        display(root->lchild);
        printf("%s\t",root->data);
        display(root->rchild);
    }
}

int main()
{
    node *root=NULL;
    int c;
    while(1)
    {
        char *ch=(char*)malloc(sizeof(char)*100);
        char *srn=(char*)malloc(100*sizeof(char));
        printf("1. Insert\n2. Display\n3. Search\n4. Exit\nEnter your choice: ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {   
                printf("Enter the SRN to be inserted: ");
                scanf("%s",srn);
                root=insert(root,srn);
                break;
            }
            case 2:
            {
                display(root);
                printf("\n");
                break;
            }
            case 3:
            {
                printf("Enter the SRN to be searched: ");
                scanf("%s",ch);
                search(root,ch);
                break;
            }
            case 4:
            {
                exit(0);
            }
        }
    }
    return 0;
}