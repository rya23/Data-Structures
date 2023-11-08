#include <stdio.h>
#include <stdlib.h>

int **list;
char *bit;
int *queue;
int msource, front, rear;

int bfs(int source)
{
    int visited, adjacent;
    int touchcount = 1;
    rear++;
    queue[rear] = source;
    printf("%d", source);
    bit[source] = 1;
    do
    {
        int dequeued = queue[front];
        // printf("%d\t", dequeued);
        front++;
        int i = 0;
        adjacent = list[dequeued][i];
        while (adjacent != -1)
        {

            if (bit[adjacent] == 0)
            {
                printf("\t%d", adjacent);
                rear++;
                queue[rear] = adjacent;
                bit[adjacent] = 1;
                touchcount++;
            }
            i++;
            adjacent = list[dequeued][i];
        }

    } while (front != rear);
    // printf("\nBFS completed");
    // printf("\n%d\n",queue[rear]);
    return touchcount;
}

int main()
{
    int num, i, j;
    printf("Enter number of nodes : ");
    scanf("%d", &num);
    bit = (char *)calloc(num, sizeof(char));
    list = (int **)malloc(num * sizeof(int));
    queue = (int *)malloc(num * sizeof(int));
    for (i = 0; i < num; i++)
    {
        int no;
        printf("Number of nodes Adjacent to %d : ", i);
        scanf("%d", &no);
        list[i] = (int *)malloc((no + 1) * sizeof(int));
        printf("Enter nodes Adjacent to %d : ", i);
        for (j = 0; j < no; j++)
        {
            scanf("%d", &list[i][j]);
        }
        list[i][j] = -1;
    }

    printf("Enter source Vertex");
    scanf("%d", &msource);
    int visited = 0;
    do
    {
        front = 0;
        rear = -1;
        visited = visited + bfs(msource);
        if (visited != num)
        {
            printf("Bfs initiated again");
            for (int i = 0; i < num; i++)
            {
                if (bit[i] == 0)
                {
                    msource = i;
                    break;
                }
            }
        }
        else
            break;

    } while (1);
}
