#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct s
{
    char SRN[100];
    char name[100];
    int sem;
    int m[5];
};
int main()
{
    printf("Enter the number of students: ");
    int n;
    scanf("%d", &n);
    struct s *ob = (struct s *)malloc(n * sizeof(struct s));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the SRN: ");
        scanf("%s", &ob[i].SRN);
        printf("Enter the name: ");
        scanf("%s", &ob[i].name);
        printf("Enter the semester: ");
        scanf("%d", &ob[i].sem);
        printf("Enter marks: ");
        for (int j = 0; j < 5; j++)
        {
            scanf("%d", &ob[i].m[j]);
        }
    }
    int sub;
    printf("Enter the subject number to find marks in: ");
    scanf("%d", &sub);
    int sum = 0;
    float avg = 0.0;
    for (int i = 0; i < n; i++)
    {
        sum += ob[i].m[sub - 1];
    }
    avg=sum/n; 
    printf("Average marks in subject %d is %.2f\n", sub, avg);
    char temp[100];
    for (int i=0;i<n-1;i++)
    {
        for (int j=i;j<n-1;j++)
        {
            if (strcmp(ob[j].SRN, ob[j + 1].SRN) > 0)
            {
                strcpy(temp, ob[j].SRN);
                strcpy(ob[j].SRN, ob[j + 1].SRN);
                strcpy(ob[j + 1].SRN, temp);
            }
        }
    }
    printf("Sorted records:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t", ob[i].SRN);
    }
    return 0;
}
