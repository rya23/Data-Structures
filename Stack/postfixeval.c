#include <stdio.h>
#include <ctype.h>

int stack[20];
int top;

void push(int e)
{
    top++;
    stack[top] = e;
}

int pop()
{
    return stack[top--];
}

int main()
{
    char exp[20];
    top = -1;
    int n3;
    printf("Enter a expression : ");
    scanf("%s", &exp);
    int i = 0;
    while (exp[i] != '\0')
    {

        if (isdigit(exp[i]))
        {
            int e = exp[i] - 48;
            push(e);
        }
        else
        {
            int n1 = pop();
            int n2 = pop();
            switch (exp[i])
            {
            case '+':
            {
                n3 = n1 + n2;
                break;
            }
            case '-':
            {
                n3 = n2 - n1;
                break;
            }
            case '*':
            {
                n3 = n1 * n2;
                break;
            }
            case '/':
            {
                n3 = n2 / n1;
                break;
            }
            }
            push(n3);
        }
        i++;
    }

    printf("\nThe result of expression %s = %d\n\n", exp, pop());
    return 0;
}
