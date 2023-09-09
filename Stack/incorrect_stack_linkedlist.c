#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char name[20];
    char div;
    int rollno;
    struct node *link;
};
struct sll
{
    struct node *head;
};
void print(struct node *student)
{
    printf("Name : %sDivision : %c \nRoll No. : %d", student->name, student->div, student->rollno);
};
char isempty(struct sll *list)
{
    return list->head == NULL;
};
void push(struct sll *list, struct node *student)
{
    struct node *studptr = list->head;
    while (studptr->link != NULL)
    {
        studptr = studptr->link;
    }
    student->link = NULL;
    studptr->link = student;
};
void pop(struct sll *list)
{
    struct node *studptr = list->head;
    while ((studptr->link)->link != NULL)
    {
        studptr = studptr->link;
    }
    printf("\nPopped node is : \n");
    print(studptr->link);
    free(studptr->link);
    studptr->link = NULL;
};
void peek(struct sll *list)
{
    struct node *studptr = list->head;
    while (studptr->link != NULL)
    {
        studptr = studptr->link;
    }
    print(studptr);
};

int main()
{
    struct node *student;
    struct sll *list;
    struct sll l;
    list=&l;
    // struct sll *list = (struct sll *)malloc(sizeof(struct sll));
    student = NULL;
    list->head = NULL;
    while (1)
    {
        int num;
        printf("\n1. Check empty  2. Push   3. Pop  4. Peek  5. Exit\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
        {
            if (isempty(list))
            {
                printf("Stack is Empty");
            }
            else
                printf("Stack is not Empty");
            break;
        }
        case 2:
        {
            student = (struct node *)malloc(sizeof(struct node));
            printf("Enter Student Details \n");
            getchar();
            printf("Name : ");
            fgets(student->name, sizeof(student->name), stdin);
            printf("Division : ");
            scanf(" %c", &(student->div));
            printf("Roll No. : ");
            scanf("%d", &(student->rollno));
            if (list->head == NULL)
            {
                list->head = student;
                student->link = NULL;
                break;
            }
            else
                push(list, student);
            break;
        }
        case 3:
        {
            if (isempty(list))
            {
                printf("Stack is Empty. Can't POP");
                break;
            }
            if (((list->head)->link) == NULL)
            {
                print(list->head);
                printf("\nStack is Empty\n");
                free(list->head);
                list->head = NULL;
                break;
            }
            else
                pop(list);
            break;
        }
        case 4:
        {
            if (isempty(list))
                printf("\nStack is Empty. ");
            else
                peek(list);
            break;
        }

        case 5:
            return 0;
        default:
            break;
        }
    }
}