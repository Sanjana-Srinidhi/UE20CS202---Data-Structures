#include <stdio.h>
#include <stdlib.h>

typedef struct poly
{
    int coeff;
    int px;
    int py;
    struct poly *next;
} poly;

void accept(poly **p, int x, int y, int z)
{
    poly *temp = (poly *)malloc(sizeof(poly));
    temp->coeff = x;
    temp->px = y;
    temp->py = z;
    temp->next = NULL;

    if (*p == NULL)
    {
        *p = temp;
    }
    else
    {
        poly *dstart = *p;
        while (dstart->next != NULL)
        {
            dstart = dstart->next;
        }
        dstart->next = temp;
    }
}

void insert(poly **p, int q)
{
    int terms, x, y, z;
    printf("Enter the number of terms in polynomial %d: ", q);
    scanf("%d", &terms);
    for (int i = 0; i < terms; i++)
    {
        printf("Enter the coefficient: ");
        scanf("%d", &x);
        printf("Enter the power of x: ");
        scanf("%d", &y);
        printf("Enter the power of y: ");
        scanf("%d", &z);
        accept(p, x, y, z);
    }
}

int compare(int x, int y)
{
    if (x == y)
        return 1;
    else if (x > y)
        return 2;
    else
        return 3;
}

void add(poly **p1, poly **p2, poly **p3)
{
    poly *d1, *d2;
    d1 = *p1;
    d2 = *p2;
    while (d1 != NULL || d2 != NULL)
    {
        if (d1 == NULL)
        {
            accept(p3, d2->coeff, d2->px, d2->py);
            d2 = d2->next;
        }
        else if (d2 == NULL)
        {
            accept(p3, d1->coeff, d1->px, d1->py);
            d1 = d1->next;
        }
        else
        {
            switch (compare(d1->px + d1->py, d2->px + d2->py))
            {
            case 1:
                if (d1->px == d2->px)
                {
                    accept(p3, d1->coeff + d2->coeff, d2->px, d2->py);
                    d1 = d1->next;
                    d2 = d2->next;
                }
                else if (d1->px > d2->px)
                {

                    accept(p3, d1->coeff, d1->px, d1->py);
                    d1 = d1->next;
                }
                else
                {
                    accept(p3, d2->coeff, d2->px, d2->py);
                    d2 = d2->next;
                }
                break;
            case 2:
                accept(p3, d1->coeff, d1->px, d1->py);
                d1 = d1->next;
                break;
            case 3:
                accept(p3, d2->coeff, d2->px, d2->py);
                d2 = d2->next;
                break;
            }
        }
    }
}

void display(const poly *p)
{
    while (p->next != NULL)
    {
        printf("%dx^%dy^%d + ", p->coeff, p->px, p->py);
        p = p->next;
    }
    if (p->px == 0 && p->py == 0)
    {
        printf("%d", p->coeff, p->px, p->py);
    }
    else
    {
        printf("%dx^%dy^%d", p->coeff, p->px, p->py);
    }
    printf("\n");
}

int main()
{
    poly *p1 = NULL, *p2 = NULL, *p3 = NULL;
    insert(&p1, 1);
    printf("First equation: ");
    display(p1);
    insert(&p2, 2);
    printf("Second equation: ");
    display(p2);
    add(&p1, &p2, &p3);
    printf("Added result: ");
    display(p3);
    return 0;
}