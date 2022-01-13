#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct trie
{
    struct trie *child[26];
    int end;
} trie;

trie *getnode()
{
    struct trie *temp;
    temp = (trie *)malloc(sizeof(trie));
    for (int i = 0; i < 26; i++)
    {
        temp->child[i] = NULL;
    }
    temp->end = 0;
    return temp;
}

trie *insert(trie *root, char *str)
{
    trie *curr = root;
    
    int index;
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        index = str[i] - 'a';
        printf("index: %d\n", index);

        if (curr->child[index] == NULL)
        {
            curr->child[index] = getnode();
        }
        curr = curr->child[index];
    }
    curr->end = 1;
    return root;
}

void display(trie *curr, char *str, int index)
{
    int j=0;
    /**if (curr == NULL)
    {
        printf("FFFF\n");
    }
    else
    {**/
        if (curr->end == 1)
        {
            str[index] = '\0';
            printf("%s\n", str);
        }
        else
        {
            for (int i = 0; i < 26; i++)
            {
                if (curr->child[i] != NULL)
                {
                    str[index] = i + 'a';
                    printf("%d\t", index);
                    j++;
                    display(curr->child[index], str, index + 1);
                }
            }
        }
    //}
}

int search(trie *root, char *str)
{
    int index;
    trie *curr;
    curr = root;
    for(int i=0; i<26; i++)
    {
        index = str[i];
        if(curr->child[index] == NULL)
        {
            return 0;
        }
        curr = curr->child[index];
    }
    if(curr->end == 1)
    {
        return 1;
    }
    return 0;
}

int main()
{
    trie *t = getnode();
    char ins[100] = "banana";
    t = insert(t, ins);
    char str[100];
    display(t, str, 0);
    return 0;
}