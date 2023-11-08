#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int front;
    int rear;
    int max;
    int *num;
};

char isempty(struct queue *s)
{
    return (s->front == -1 && s->rear == -1);
}

char isfull(struct queue *s)
{
    return ((s->rear+1)%s->max == s->front);
}

void enqueue(struct queue *s, int *num)
{

    if (isempty(s))
        s->front = s->rear = 0;
    else
        s->rear=(s->rear+1)%s->max;
    s->num[s->rear] = *num;
}

void dequeue(struct queue *s)
{
    printf("\n%d is dequeued\n", s->num[s->front]);
    if (s->front == s->rear)
    {
        s->front = -1;
        s->rear = -1;
    }
    else s->front = (s->front+1)%s->max;
}

void front(struct queue *s)
{
    printf("Front of queue is : %d", s->num[s->front]);
}

int main()
{
    struct queue *s1 = (struct queue *)malloc(sizeof(struct queue));
    s1->front = -1;
    s1->rear = -1;
    printf("Enter maximum size of array : ");
    scanf("%d", &s1->max);
    s1->num = (int *)malloc(s1->max * sizeof(int));
    while (1)
    {
        int num;
        printf("\n1. Check empty  2. Check full  3. Enqueue   4. Dequeue  5. Front  6. Exit\n");
        scanf("%d", &num);

        switch (num)
        {
        case 1:
        {
            if (isempty(s1))
            {
                printf("queue is Empty");
            }
            else
                printf("queue is not Empty");
            break;
        }
        case 2:
        {
            if (isfull(s1))
            {
                printf("queue is Full");
            }
            else
                printf("queue is not Full");
            break;
        }
        case 3:
        {
            int *num = (int *)malloc(sizeof(int));
            if (isfull(s1))
                printf("queue is Full. Can't Enqueue");
            else
            {
                int num;
                printf("\nEnter number to enqueue : ");
                scanf("%d", &num);
                enqueue(s1, &num);
            }
            break;
        }
        case 4:
        {
            if (isempty(s1))
                printf("queue is Empty. Can't Enqueue");
            else
            {
                dequeue(s1);
            }
            break;
        }
        case 5:
        {
            if (isempty(s1))
                printf("queue is Empty");
            else
            {
                front(s1);
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
