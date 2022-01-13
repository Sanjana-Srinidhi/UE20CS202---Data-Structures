#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct stack
{
    char a[max];
    int top;
} stack;

void init(stack *s);
void push(stack *s, char ch);
char pop(stack *s);
char peek(stack *s);
int compute(char *str);

void init(stack *s)
{
    s->top = -1;
}

void push(stack *s, char ch)
{
    s->top = s->top + 1;
    s->a[s->top] = ch;
}

char pop(stack *s)
{
    char ch;
    ch = s->a[s->top];
    s->top = s->top - 1;
}

char peek(stack *s)
{
    return s->a[s->top];
}

int compute(char *str)
{
    stack *s = (stack *)malloc(sizeof(stack));
    s->top = -1;
    char ch;
    char x;
    int flag = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        ch = str[i];
        switch (ch)
        {
        case '(':
        {
            push(s, ch);
            break;
        }
        case '{':
        {
            push(s, ch);
            break;
        }
        case '[':
        {
            push(s, ch);
            break;
        }
        case ']':
        {
            if ((peek(s)) == '[')
            {
                flag = 1;
                pop(s);
            }
            else
                return 0;
            break;
        }
        case ')':
        {
            if ((peek(s)) == '(')
            {
                flag = 1;
                pop(s);
            }
            else
                return 0;
            break;
        }
        case '}':
        {
            if ((peek(s)) == '{')
            {
                flag = 1;
                pop(s);
            }
            else
                return 0;
            break;
        }
        }
    }
    return flag;
}

int main()
{
    char str[100];
    printf("Enter the string: ");
    scanf("%s", &str);
    int res = compute(str);
    printf("%d", res);
    return 0;
}