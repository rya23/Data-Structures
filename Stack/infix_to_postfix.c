#include <stdio.h>
#include <ctype.h>
char stack[50];
int top = -1;
void Push(char x)
{
    stack[++top] = x;
}
char Pop()
{
    if (top == -1)
        return -1;
    else
        return stack[top--];
}
int Priority(char x)
{
    if (x == '(')
        return 0;
    else if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/' || x == '%')
        return 2;
    else if (x == '^')
        return 3;
}
int main()
{
    char e[100];
    char x;
    printf("Enter the expression: ");
    scanf("%s", &e);
    int i = 0;
    while (e[i] != '\0')
    {
        if (isalnum(e[i]))
        {
            printf("%c", e[i]);
        }
        else if (e[i] == '(')
        {
            Push(e[i]);
        }
        else if (e[i] == ')')
        {
            char x;
            while ((x = Pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (Priority(stack[top]) >= Priority(e[i]))
            {
                printf("%c", Pop());
            }
            Push(e[i]);
        }
        i++;
    }
    while (top != -1)
        printf("%c", Pop());
    return 0;
}