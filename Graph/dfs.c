#include <stdio.h>
#include <stdlib.h>

int **list;
char *bit;
int visited;

void dfs(int source)
{
    int adjacent;
    int i = 0;
    adjacent = list[source][i];
    while (adjacent != -1)
    {
        if (bit[adjacent] == 0)
        {
            visited++;
            printf("%d\t", adjacent);
            bit[adjacent] = 1;
            dfs(adjacent);
        }
        i++;
        adjacent = list[source][i];
    }
}

int main()

{
    int num, i, j, msource;
    printf("Enter number of nodes : ");
    scanf("%d", &num);
    list = (int **)malloc(num * sizeof(int *));
    bit = (char *)calloc(num, sizeof(char));

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

    visited = 0;

    do
    {
        printf("%d\t", msource);

        visited++;
        bit[msource] = 1;
        dfs(msource);
        if (visited != num)
        {
            for (int i = 0; i < num; i++)
            {
                if (bit[i] == 0)
                {
                    msource = i;
                    break;
                }
            }
            printf("\nnew source ");
        }
        else
            break;

    } while (1);
}