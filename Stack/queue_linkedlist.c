#include <stdio.h>
#include <stdlib.h>

struct list
{
    int no;
    struct list *next;
};
struct sll
{
    struct list *head;
    struct list *tail;
};

void dequeue(struct sll *start)
{
    struct list *temp = start->head;
    start->head = (start->head)->next;
    free(temp);
}

void enqueue(struct sll *start, struct list *num)
{
    (start->tail)->next = num;
    start->tail=num;
}

void traverse(struct sll *list)
{
    struct list *nodeptr;
    nodeptr = (*list).head;
    while (nodeptr != NULL)
    {
        printf("%d\t", (*nodeptr).no);
        nodeptr = (*nodeptr).next;
    }

    printf("\n");
}

void peek(struct sll *list)
{
    printf("%d\t", (list->head)->no);
}

int main()

{

    struct sll *listptr = (struct sll *)malloc(sizeof(struct sll));
    struct list *nodeptr;
    listptr->head = NULL;
    listptr->tail = NULL;
    nodeptr = NULL;
    int num;
    while (1)
    {
        printf("\n1.Enqueue  2.Dequeue 3. Peek 8.Exit\n");
        printf("Enter the number: ");
        scanf("%d", &num);
        switch (num)
        {

        case 1:
        {
            nodeptr = (struct list *)malloc(sizeof(struct list));
            printf("Enter number to be added : ");
            scanf("%d", &(*nodeptr).no);
            nodeptr->next = NULL;
            if (listptr->tail == NULL)
            {
                listptr->head = nodeptr;
                listptr->tail = nodeptr;
            }
            else
                enqueue(listptr, nodeptr);

            break;
        }
        case 2:
        {
            if ((*listptr).head == NULL)
            {
                printf("List is empty");
                break;
            }
            if ((listptr->head)->next == NULL)
            {
                printf("List only contains one node \n Emptying the list\n");
                free((*listptr).head);
                (*listptr).head = NULL;
                break;
            }
            else
                dequeue(listptr);
            break;
        }
        case 3:
        {
            if (listptr->head == NULL)
                printf("Empty");
            else
                peek(listptr);
            break;
        }

        case 8:
        {
            printf("Exiting");
            return 0;
        }
        default:
            break;
        }
    }
}