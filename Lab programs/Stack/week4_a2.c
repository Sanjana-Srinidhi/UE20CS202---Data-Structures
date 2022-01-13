#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
    int flag;
} node;

typedef struct stack
{
    int size;
    node *top;
} stack;

int ret_flag(stack *s)
{
    return s->top->flag;
}

void init(stack *s)
{
    s->size = 0;
    s->top = NULL;
}

void push(stack *s, int ele, int flag)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = ele;
    temp->flag = flag;
    temp->next = NULL;
    if (s->top == NULL)
    {
        s->top = temp;
    }
    else
    {
        temp->next = s->top;
        s->top = temp;
    }
}

int pop(stack *s)
{
    if (s->top == NULL)
    {
        return -1;
    }
    else
    {
        node *temp = s->top;
        int x = temp->data;
        s->top = s->top->next;
        free(temp);
        temp = NULL;
        return x;
    }
}

int peek(stack *s)
{
    if (s->top == NULL)
    {
        return -1;
    }
    else
    {
        return s->top->data;
    }
}

void process()
{
    char ch[50];
    int ele[50];
    int i = 0;
    printf("Enter A for arrival or D for departure followed by license plate number\nEnter E 9999 to stop taking input\n");
    while (1 != 0)
    {
        scanf("%c %d", &ch[i], &ele[i]);
        if (ch[i] == 'E')
        {
            break;
        }
        i++;
    }
    int j, k;
    for (j = 1, k = 2; k < i; j++, k += 2)
    {
        //printf("%c\t%d\n", ch[j], j);
        ch[j] = ch[k];
        ele[j] = ele[k];
    }
    //Printing the Input text
    /*for (int l = 0; l < j; l++)
    {
        printf("%c\t%d\n", ch[l], ele[l]);
    }*/

    stack *s = (stack *)malloc(sizeof(stack));
    stack *aux = (stack *)malloc(sizeof(stack));
    init(s);
    init(aux);
    int l;
    int x, flag = 0;
    for (l = 0; l < j; l++)
    {
        switch (ch[l])
        {
        case 'A':
            if (s->size == 8)
            {
                printf("Garage is full, No more cars can be entered\n\n");
            }
            else
            {
                printf("Car with License plate No %d entering\n\n", ele[l]);
                s->size++;
                push(s, ele[l], 0);
            }
            break;
        case 'D':
            if (peek(s) == ele[l])
            {
                printf("Car with License plate No %d exiting\nThe number of times this car had to move for other cars to exit is: %d\n\n", ele[l], flag);
            }
            else
            {

                while (peek(s) != ele[l])
                {
                    flag = ret_flag(s);
                    x = pop(s);
                    push(aux, x, flag);
                }
                printf("Car with License plate No %d exiting\nThe number of times this car had to move for other cars to exit is: %d\n\n", ele[l], flag);
                pop(s);
                while (peek(aux) != -1)
                {
                    flag = ret_flag(aux) + 1;
                    x = pop(aux);
                    push(s, x, flag);
                }
            }
            break;
        }
    }
}

int main()
{
    process();
    return 0;
}