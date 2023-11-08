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
};

void addfront(struct sll *head, struct list *num)
{
    num->next = head->head;
    head->head = num;
}

void deletefront(struct sll *start)
{
    struct list *temp = start->head;
    start->head = (start->head)->next;
    free(temp);
}

void addend(struct sll *start, struct list *num)
{
    struct list *temp = start->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = num;
}

void deleteend(struct sll *start)
{
    struct list *temp = start->head;
    while ((temp->next)->next != NULL)
    {
        temp = temp->next;
    }
    struct list *a = temp->next;
    temp->next = NULL;
    free(a);
}
void addgeneral(struct sll *start, struct list *num, int k)
{
    struct list *temp2;
    struct list *temp = start->head;
    while (temp->next != NULL && k != 1)
    {
        temp = temp->next;
        k--;
    }
    if (temp->next == NULL)
    {
        printf("List is smaller than number");
        return;
    }
    else
    {
        temp2 = temp->next;
        temp->next = num;
        num->next = temp2;
    }
}
void deletegeneral(struct sll *start, int k)
{
    struct list *temp2;
    struct list *temp = start->head;
    while ((temp->next) != NULL && k != 1)
    {
        temp = temp->next;
        k--;
    }
    if ((temp->next) == NULL)
    {
        printf("List is smaller than number");
        return;
    }
    else
    {
        temp2=(temp->next)->next;
        free(temp->next);
        temp->next=temp2;
    }
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

int main()

{

    struct sll *listptr = (struct sll *)malloc(sizeof(struct sll));
    struct list *nodeptr;
    listptr->head=NULL;
    nodeptr = NULL;
    int num;
    while (1)
    {
        printf("\n1. Addfront 2.Deletefront  3.Addend   4.Deleteend  5.Traverse   6.Addgeneral   7.Deletegeneral 8.Exit\n");
        printf("Enter the number: ");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
        {
            nodeptr = (struct list *)malloc(sizeof(struct list));
            printf("Enter number to be added : ");
            scanf("%d", &(nodeptr->no));
            addfront(listptr, nodeptr);
            break;
        }
        case 2:
        {
            if ((*listptr).head == NULL)
            {
                printf("List is empty");
            }
            if ((listptr->head)->next == NULL)
            {
                printf("List only contains one node \n Emptying the list\n");
                free((*listptr).head);
                (*listptr).head = NULL;
                break;
            }
            else
                deletefront(listptr);
            break;
        }
        case 3:
        {
            nodeptr = (struct list *)malloc(sizeof(struct list));
            printf("Enter number to be added : ");
            scanf("%d", &(*nodeptr).no);
            nodeptr->next = NULL;
            if ((*listptr).head == NULL)
            {
                addfront(listptr, nodeptr);
            }
            else
            {
                addend(listptr, nodeptr);
            }
            break;
        }
        case 4:
        {
            if ((*listptr).head == NULL)
            {
                printf("\nList is Empty\n");
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
            {

                deleteend(listptr);
                break;
            }
        }
        case 5:
        {
            if ((*listptr).head == NULL)
            {
                printf("List is Empty");
                break;
            }
            traverse(listptr);
            break;
        }
        case 6:
        {
            int k;
            nodeptr = (struct list *)malloc(sizeof(struct list));
            printf("\nEnter number to be added and position after which it is added : ");
            scanf("%d%d", &(*nodeptr).no, &k);
            // if ((*listptr).head == NULL && k == 0)
            // {
            //     (*listptr).head = nodeptr;
            //     (*nodeptr).link = NULL;
            //     break;
            // }
            // else if
            if (k < 1)
            {
                printf("Enter a valid value");
                break;
            }

            else
            {
                addgeneral(listptr, nodeptr, k);
                break;
            }
        }
        case 7:
        {
            if ((*listptr).head == NULL)
            {
                printf("\nList is empty\n");
                break;
            }
            int k;
            printf("Enter postion after which number is deleted : ");
            scanf("%d", &k);
            // if (k == 0)
            // {
            //     deleteend(listptr);
            // }
            if (k < 1)
            {
                printf("Enter a valid value");
            }
            else
            {
                    deletegeneral(listptr, k);
            }
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