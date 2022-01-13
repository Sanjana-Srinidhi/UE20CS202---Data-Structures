#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Department
{
    char *name;
    int number;
} Department;

typedef struct Node
{
    char *SSN;
    char *name;
    Department *d;
    char *designation;
    int salary;
    int pno;
    int age;
    struct Node *llink, *rlink;
} Node;

typedef struct Employees
{
    Node *head;
} Employees;

Node *create(Node *temp)
{
    // Allocating memory
    temp = (Node *)malloc(sizeof(Node));
    temp->SSN = (char *)malloc(sizeof(20 * sizeof(char)));
    temp->name = (char *)malloc(sizeof(20 * sizeof(char)));
    temp->designation = (char *)malloc(sizeof(20 * sizeof(char)));
    temp->d = (Department *)malloc(sizeof(Department));
    temp->d->name = (char *)malloc(sizeof(20 * sizeof(char)));
    temp->rlink = temp->llink = NULL;

    //Initialising variables
    printf("Enter the SSN: ");
    scanf("%s", temp->SSN);
    printf("Enter the Name: ");
    scanf("%s", temp->name);
    printf("Enter department name followed by department code:\n");
    scanf("%s\n%d", temp->d->name, &temp->d->number);
    printf("Enter the Designation: ");
    scanf("%s", temp->designation);
    printf("Enter the Salary: ");
    scanf("%d", &temp->salary);
    printf("Enter the phone number: ");
    scanf("%d", &temp->pno);
    printf("Enter the age: ");
    scanf("%d", &temp->age);
    return temp;
}

void insert(Employees *p)
{
    Node *temp;
    temp = create(temp);
    //printf("%s\t%s\t%d\n", temp->SSN, temp->d->name, temp->d->number);
    if (p->head == NULL)
    {
        p->head = temp;
    }
    else
    {
        temp->rlink = p->head;
        (p->head)->llink = temp;
        p->head = temp;
    }
}

void show(Employees *p)
{
    Node *temp;
    temp=p->head;
    while(temp!=NULL)
    {
        printf("%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\n", temp->SSN, temp->name, temp->d->name, temp->d->number, temp->designation, temp->salary, temp->pno, temp->age);
        temp=temp->rlink;
    }
}

void del(Employees *p)
{
    Node *temp = p->head;
    while (temp->rlink != NULL)
    {
        if (temp->age > 58)
        {
            if (temp->llink == NULL)
            {
                p->head = temp->rlink;
                (p->head)->llink = NULL;
                free(temp);
                temp = p->head;
            }
            else
            {
                Node *dummy = temp;
                temp->llink->rlink = temp->rlink;
                temp->rlink->llink = temp->llink;
                temp = temp->rlink;
                free(dummy);
                dummy = NULL;
            }
        }
        temp = temp->rlink;
    }
    if (temp->rlink == NULL && temp->llink != NULL)
    {
        temp->llink->rlink = NULL;
        free(temp);
    }
    else
    {
        free(temp);
        p->head = temp = NULL;
    }
}

void display(Employees *p, char *check)
{
    Node *head = p->head;
    int f = 0;
    while (head != NULL)
    {
        if (strcmp(head->d->name, check) == 0)
        {
            f++;
            printf("%s\t%s\t%s\t%d\t%s\t%d\t%d\t%d\n", head->SSN, head->name, head->d->name, head->d->number, head->designation, head->salary, head->pno, head->age);
        }
        head = head->rlink;
    }
    if (f == 0)
    {
        printf("No record found with the department name %s\n", check);
    }
}

int main()
{
    Employees p;
    p.head = NULL;
    int choice;
    char check[10];
    while (1 != 0)
    {

        printf("1. Insert record\n2. Delete all employees whose age is above 58\n3. Display the details of all employees from a particular department\n4. Display all records\n5. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert(&p);
            break;
        case 2:
            del(&p);
            break;
        case 3:
            printf("Enter the department: ");
            scanf("%s", check);
            display(&p, check);
            break;
        case 4:
            show(&p);
            break;
        case 5:
            exit(0);
        }
        printf("\n");
    }
    return 0;
}