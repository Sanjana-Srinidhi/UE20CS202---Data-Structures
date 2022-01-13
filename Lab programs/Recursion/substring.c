#include<stdio.h>
#include<string.h>

int main()
{
    char str[100], sub[100];
    printf("Enter the first string: ");
    gets(str);
    printf("Enter the second string: ");
    gets(sub);
    printf("%d", f(str, sub, 0, 0));
    return 0;
}

int f(char str[10], char sub[10], int f1, int f2)
{
    if (sub[f2] == '\0')
        return 1;
    else if (str[f1] == '\0')
        return 0;
    else
    {
        if (str[f1] == sub[f2])
            return f(str, sub, f1 + 1, f2 + 1);
        else
            return f(str, sub, f1 + 1, 0);
    }
}