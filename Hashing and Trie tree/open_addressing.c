#include <stdio.h>
#include <stdlib.h>

typedef struct hash
{
    int key;
    int mark;
} hash;

void init(hash *head)
{
    for (int i = 0; i < 10; i++)
    {
        head[i].mark = 0;
        head[i].key = 0;
    }
}

void insert_linear(hash *head, int key)
{
    int index;
    index = key % 10;
    while (head[index].mark != 0)
    {
        index = (index + 1) % 10;
    }
    head[index].mark = 1;
    head[index].key = key;
}

void insert_quadruple(hash *head, int key)
{
    int index;
    int temp;
    int i = 0;
    index = key % 10;
    temp = index;
    while (head[temp].mark != 0)
    {
        temp = (index + i * i) % 10;
        i++;
    }
    head[temp].mark = 1;
    head[temp].key = key;
}

void display(hash *head)
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", head[i].key);
    }
}

int main()
{
    hash *head_linear = (hash *)malloc(sizeof(hash));
    hash *head_quadruple = (hash *)malloc(sizeof(hash));
    init(head_linear);
    init(head_quadruple);
    insert_linear(head_linear, 5);
    insert_linear(head_linear, 7);
    insert_linear(head_linear, 9);
    insert_linear(head_linear, 15);
    insert_linear(head_linear, 17);
    printf("Linear probing: ");
    display(head_linear);
    printf("\n");
    insert_quadruple(head_quadruple, 5);
    insert_quadruple(head_quadruple, 7);
    insert_quadruple(head_quadruple, 9);
    insert_quadruple(head_quadruple, 15);
    insert_quadruple(head_quadruple, 17);
    printf("Quadruple probing: ");
    display(head_quadruple);
    printf("\n");
    return 0;
}
