#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};
struct node *treeptr;

struct node *insert(struct node *treeptr, int data)
{
    struct node *nodeptr, *parentptr;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;
    if (treeptr == NULL)
    {
        treeptr = temp;
    }
    else
    {
        parentptr = NULL;
        nodeptr = treeptr;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (nodeptr->data > data)
            {
                nodeptr = nodeptr->left;
            }
            else
                nodeptr = nodeptr->right;
        }
        if (data < parentptr->data)
            parentptr->left = temp;
        else
            parentptr->right = temp;
    }
    return treeptr;
};

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

char search(struct node *root, int data)
{
    if (root == NULL)
        return 0;
    if (root->data == data)
        return 1;

    else if (root->data < data)
    {
        search(root->right, data);
    }
    else
        search(root->left, data);
}

struct node *minimum(struct node *root)
{
    if ((root == NULL) || (root->left == NULL))
        return root;
    else
        return minimum(root->left);
}

struct node *delete(struct node *root, int num)
{
    if (root == NULL)
        root = root;
    if (root->data < num)
        root->right = delete (root->right, num);
    else if (root->data > num)
        root->left = delete (root->left, num);
    else{
    if (root->left == NULL)
    {
        struct node *temp = root->right;
        free(root);
        return temp;
    }
    if (root->right == NULL)
    {
        struct node *temp = root->left;
        free(root);
        return temp;
    }
    else
    {
        struct node* temp1 = minimum(root->right);
        root->data=temp1->data;
        root->right=delete(root->right,temp1->data);
    }
    return root;
    }
}

int main()
{
    treeptr = NULL;

    while (1)
    {
        int num;
        printf("\n1.Insertion 2.Deletion 3.Searching 4.Traverse 5.Minimum Element \n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
        {
            int no;
            printf("Enter Element to be added");
            scanf("%d", &no);
            treeptr = insert(treeptr, no);
            break;
        }

        case 2:
        {
            int no;
            printf("Enter Element to be Deleted");
            scanf("%d", &no);
            if(treeptr==NULL) printf("Empty Tree");
            else treeptr=delete(treeptr, no);
            break;
        }

        case 3:
        {
            int no;
            printf("Enter Element to be Searched");
            scanf("%d", &no);
            if (search(treeptr, no))
                printf("\nFound\n");
            else
                printf("\nNot found\n");
            break;
        }

        case 4:
        {
            preorder(treeptr);
            break;
        }

        case 5:
        {
            struct node *min = minimum(treeptr);
            if (min == NULL)
                printf("Empty tree");
            else
                printf("\n%d is the minimum Element\n", min->data);
            break;
        }
        }
    }

    printf("Hello");
}