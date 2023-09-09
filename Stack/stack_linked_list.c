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
struct stack
{
    struct node *top;
};
void print(struct node *student)
{
    printf("Name : %sDivision : %c \tRoll No. : %d", student->name, student->div, student->rollno);
};
char isempty(struct stack *list)
{
    return list->top == NULL;
};
void push(struct stack *list, struct node *student)
{
    student->link = list->top;
    list->top = student;
};
void pop(struct stack *list)
{

    struct node *studptr = list->top;
    struct node *temp = list->top;
    list->top = studptr->link;
    printf("\nPopped node is : \n");
    print(temp);
    free(temp);
};
void peek(struct stack *list)
{
    print(list->top);
};

int main()
{
    struct node *student;

    struct stack l,*list;
    list = &l;
    // struct stack *list = (struct stack *)malloc(sizeof(struct stack));
    student = NULL;
    list->top = NULL;
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