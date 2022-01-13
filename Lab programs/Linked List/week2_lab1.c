#include <stdio.h>
#include <stdlib.h>

void insert(int ele);
void display();
void swap();
void delete ();

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    display();
    swap();
    printf("Nodes after swapping: \n");
    display();
    delete ();
    printf("Nodes after deletion of alternate nodes:\n ");
    display();
    return 0;
}

void insert(int ele)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *temp;
    temp = head;
    new->data = ele;
    if (temp == NULL)
    {
        head = new;
        new->next = NULL;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new;
        new->next = NULL;
    }
}

void display()
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void swap()
{
    struct node *pres1;
    struct node *pres2;
    struct node *prev1;
    struct node *prev2;
    struct node *temp;
    prev1 = NULL;
    prev2 = NULL;
    pres1 = head;
    pres2 = head;
    temp = NULL;
    int ele1;
    int ele2;
    printf("Enter the first element to swap: ");
    scanf("%d", &ele1);
    printf("Enter the second element to swap: ");
    scanf("%d", &ele2);
    while (pres1 != NULL && pres1->data != ele1)
    {
        prev1 = pres1;
        pres1 = pres1->next;
    }
    while (pres2 != NULL && pres2->data != ele2)
    {
        prev2 = pres2;
        pres2 = pres2->next;
    }
    if (pres1 != NULL && pres2 != NULL)
    {
        if (prev1 != NULL)
        {
            prev1->next = pres2;
        }
        else
        {
            head = pres2;
        }
        if (prev2 != NULL)
        {
            prev2->next = pres1;
        }
        else
        {
            head = pres1;
        }
        temp = pres1->next;
        pres1->next = pres2->next;
        pres2->next = temp;
    }
}

void delete ()
{
    struct node *temp = head;
    head = head->next;
    free(temp);
    struct node *del = NULL;
    temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        del = temp->next;
        temp->next = temp->next->next;
        temp = temp->next;
        free(del);
    }
}