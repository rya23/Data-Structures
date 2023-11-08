void traverse(struct sll *list)
{
    struct node *nodeptr;
    nodeptr = (*list).head;
    do
    {
        printf("%d\t", (*nodeptr).no);
        nodeptr = (*nodeptr).link;
    } while (nodeptr != NULL);

    printf("\n");
};