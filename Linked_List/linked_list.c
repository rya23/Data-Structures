#include<stdio.h>
#include<stdlib.h>

struct node
{
    int no;
    struct node* link;

};
struct sll
{
    struct node *head;
};

void addfront(struct sll *list,struct node *nodeptr)
{
    (*nodeptr).link=(*list).head;
    (*list).head=nodeptr;

};
void addend(struct sll* list,struct node *node)
{   struct node *nodeptr;
    nodeptr=(*list).head;
    while((*nodeptr).link != NULL)
    {
        nodeptr=(*nodeptr).link;
    }
    (*node).link=NULL;
    (*nodeptr).link=node;


};


void deletefront(struct sll* list)
{
    struct node *nodeptr;
    nodeptr=(*list).head;
    (*list).head=(*nodeptr).link;
    free(nodeptr);

};
void deleteend(struct sll* list)
{
    struct node *nodeptr;
    nodeptr=(*list).head;
    while ((*(*nodeptr).link).link!=NULL)
    {
        nodeptr=(*nodeptr).link;
    }
    free((*nodeptr).link);
    (*nodeptr).link=NULL;
};
void addgen(struct sll* list , struct node *nodepoint,int k)
{
    struct node *nodeptr,*temp;
    nodeptr = (*list).head;
    while((*nodeptr).link != NULL && k!=1)
    {
        nodeptr=(*nodeptr).link;
        k--;
    }
    if(k>1)
    {
        printf("List is smaller than index number.\n");
    }
    else
    {
        temp=(*nodeptr).link;
        (*nodeptr).link=nodepoint;
        (*nodepoint).link=temp;
    }
};

void delgen(struct sll* list ,int k)
{
    struct node *nodeptr,*temp;
    nodeptr = (*list).head;
    while((*nodeptr).link != NULL && k!=1)
    {
        nodeptr=(*nodeptr).link;
        k--;
    }
    if(k>1)
    {
        printf("List is smaller than index number.\n");
    }
    else
    {
        temp=(*(*nodeptr).link).link;
        free((*nodeptr).link);
        (*nodeptr).link=temp;
    }

};

void traverse(struct sll *list)
{
    struct node *nodeptr;
    nodeptr=(*list).head;
    do
    {
    printf("%d\t",(*nodeptr).no);
    nodeptr=(*nodeptr).link;
    }while(nodeptr != NULL);

    printf("\n");
};




int main()
{   struct node *nodepointer;
    struct sll list;
    struct sll *listpointer;
    int num;


    nodepointer= NULL;
    list.head=NULL;
    listpointer = &list;

    while(1)
   { printf("\n1. Addfront 2.Deletefront  3.Addend   4.Deleteend  5.Traverse   6.Addgeneral   7.Deletegeneral 8.Exit\n");
    printf("Enter the number: ");
    scanf("%d",&num);
    switch(num)
    {
        case 1:
        {
            nodepointer = (struct node*)malloc(sizeof(struct node));
            printf("Enter number to be added : ");
            scanf("%d",&(*nodepointer).no);
            if((*listpointer).head==NULL)
            {
                (*listpointer).head=nodepointer;
                (*nodepointer).link=NULL;

            }
            else addfront(listpointer,nodepointer);
            break;
        }
        case 2:
        {   if((*listpointer).head==NULL)
            {
                printf("List is empty");
            }

            else deletefront(listpointer);
            break;
        }
        case 3:
        {
            nodepointer = (struct node*)malloc(sizeof(struct node));
            printf("Enter number to be added : ");
            scanf("%d",&(*nodepointer).no);
            if((*listpointer).head==NULL)
            {
                addfront(listpointer,nodepointer);
            }
            else
            {addend(listpointer,nodepointer);}
            break;
        }
        case 4:
            {
                if((*listpointer).head==NULL)
                {
                    printf("\nList is Empty\n");
                    break;
                }
                if(((*(*listpointer).head).link)==NULL)
                {
                    printf("List only contains one node \n Emptying the list\n");
                    free((*listpointer).head);
                    (*listpointer).head=NULL;
                    break;
                }
                else
                {                      printf("\nList is Empty\n");

                    deleteend(listpointer);
                    break;
                }
            }
        case 5: {
                if((*listpointer).head==NULL)
                {
                    printf("List is Empty");
                    break;
                }
                traverse(listpointer);
                break;
        }
        case 6:
            {   int k;
                nodepointer = (struct node*)malloc(sizeof(struct node));
                printf("\nEnter number to be added and position after which it is added : ");
                scanf("%d%d",&(*nodepointer).no,&k);
                if(k<1)
                {   printf("Enter a valid value");
                    break;
                }

                else
                {
                    addgen(listpointer,nodepointer,k);
                    break;
                }

            }
        case 7:
            {
                int k;
                printf("Enter postion after which number is deleted : ");
                scanf("%d",&k);
                if(k<0)
                {   printf("Enter a valid value");
                }
                else
                {
                    delgen(listpointer,k);
                }
                break;
            }

        case 8: return 0;
        default: break;

    }



}}
