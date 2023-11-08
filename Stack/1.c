#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int max;
    int *num;
};

char isempty(struct stack *s)
{
    return s->top == -1;
}
char isfull(struct stack *s)
{
    return s->top == s->max-1;
}

void push(struct stack *s, int num)
{
    s->top++;
    s->num[s->top] = num;
}

void peek(struct stack *s)
{
    printf("%d", s->num[s->top]);
}

void pop(struct stack *s)
{
    peek(s);
    s->top--;
}
int main()
{
    int max;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    printf("Enter total elements of array");
    scanf("%d", &(max));
    s->max=max;
    s->top = -1;
    s->num = (int *)malloc(s->max * sizeof(int));

    while (1)
    {
        int num;
        printf("\n1. Check empty  2. Check full  3. Push   4. Pop  5. Peek  6. Exit\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
        {
            if (isempty(s))
            {
                printf("Stack is Empty");
            }
            else
                printf("Stack is not Empty");
            break;
        }
        case 2:
        {
            if (isfull(s))
            {
                printf("Stack is Full");
            }
            else
                printf("Stack is not Full");
            break;
        }
        case 3:
        {
            if (isfull(s))
                printf("Cant push");
            else
            {
                int num;
                printf("\nEnter number to enqueue : ");
                scanf("%d", &num);
                push(s, num);
            }

            break;
        }
        case 4:
        {
            if (isempty(s))
                printf("Stack is Empty. Can't POP");
            else
            {
                pop(s);
            }
            break;
        }
        case 5:
        {
            if (isempty(s))
                printf("Stack is Empty");
            else
            {
                peek(s);
            }
            break;
        }

        case 6:
            return 0;
        default:
            printf("\nInvalid Input\n");
        }
    }
}
