#include <stdio.h>
#include <stdlib.h>

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
    printf("\nName : %s ", stud.name);
    printf("\nDivision : %d", stud.div);
    printf("\nRoll No. : %d", stud.rollno);
};
void pop(struct stack *s)
{   printf("\nPopped Values are : \n");
    peek(s);
    s->top--;
}
int main()
{
    struct student *stud;
    struct stack *s1;
    s1->top = 0;
    printf("Enter maximum size of array : ");
    scanf("%d", &s1->max);
    while (1)
    {
        int num;
        printf("\n1. Check empty  2. Check full  3. Peek   4. Push  5. Pop  6. Exit\n");
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
            if (isempty(s1))
                printf("Stack is Empty");
            else
            {
                peek(s1);
            }
            break;
        }
        case 4:
        {
            if (isfull(s1))
                printf("Stack is Full Cant PUSH");
            else
            {
                stud = (struct student *)malloc(sizeof(struct student));
                printf("Enter Student Details \n");
                printf("Name : ");
                scanf("%s", &(stud->name));
                printf("Division : ");
                scanf("%d", &(stud->div));
                printf("Roll No. : ");
                scanf("%d", &(stud->rollno));
                push(s1, stud);
            }
            break;
        }
        case 5:
        {
            if (isempty(s1)) printf("Stack is Empty Cant POP");
            else
            {
                pop(s1);
            }
            break;
        }

        case 6:
            return 0;
        }
    }
}
