#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[20];
    char div;
    int rollno;
};

struct stack
{
    unsigned int max;
    unsigned int top;
    struct student array[];
};

char isempty(struct stack *s)
{
    return s->top == 0;
};
char isfull(struct stack *s)
{
    return s->top == s->max;
};
void push(struct stack *s, struct student *stud)
{
    s->top++;
    s->array[s->top] = *stud;
};
void peek(struct stack *s)
{
    struct student stud = s->array[s->top];
    printf("Name : %s\nDivision : %c \nRoll No. : %d", stud.name, stud.div, stud.rollno);
};
void pop(struct stack *s)
{
    printf("\nPopped Values are : \n");
    peek(s);
    s->top--;
}
int main()
{
    struct student *stud;
    struct stack *s1 = (struct stack *)malloc(sizeof(struct stack));;
    s1->top = 0;
    printf("Enter maximum size of array : ");
    scanf("%d", &s1->max);
    while (1)
    {
        int num;
        printf("\n1. Check empty  2. Check full  3. Push   4. Pop  5. Peek  6. Exit\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
        {
            if (isempty(s1))
            {
                printf("Stack is Empty");
            }
            else
                printf("Stack is not Empty");
            break;
        }
        case 2:
        {
            if (isfull(s1))
            {
                printf("Stack is Full");
            }
            else
                printf("Stack is not Full");
            break;
        }
        case 3:
        {
            if (isfull(s1))
                printf("Stack is Full. Can't PUSH");
            else
            {
                stud = (struct student *)malloc(sizeof(struct student));
                printf("Enter Student Details \n");
                getchar();
                printf("Name : ");
                fgets(stud->name, sizeof(stud->name), stdin);
                printf("Division : ");
                scanf(" %c", &(stud->div));
                printf("Roll No. : ");
                scanf("%d", &(stud->rollno));
                push(s1, stud);
            }
            break;
        }
        case 4:
        {
            if (isempty(s1))
                printf("Stack is Empty. Can't POP");
            else
            {
                pop(s1);
            }
            break;
        }
        case 5:
        {
            if (isempty(s1))
                printf("Stack is Empty");
            else
            {
                peek(s1);
            }
            break;
        }

        case 6:
            return 0;
        default : printf("\nInvalid Input\n");
        }
    }
}
