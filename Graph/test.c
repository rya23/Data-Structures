#include <stdio.h>
#include <malloc.h>

char *bit;
int *parent;
int *Q;
int **VAL;
int n;
int mainsource;
int front, rear;
int visitcount;

int bfs(int);
void printshortestpathto(int);

int main()
{
	int i, ac, j;

	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	VAL = (int **)malloc(n * sizeof(int *));
	bit = (char *)calloc(n, sizeof(char));
	parent = (int *)malloc(n * sizeof(int));
	Q = (int *)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		printf("How many vertices adjacent to vertex %d ?", i);
		scanf("%d", &ac);

		VAL[i] = (int *)malloc((ac + 1) * sizeof(int));
		printf("Enter names of %d adjacent vertices: ", ac);
		for (j = 0; j < ac; j++)
		{
			scanf("%d", &VAL[i][j]);
		}
		VAL[i][j] = -1;
	}

	printf("Enter the source vertex: ");
	scanf("%d", &mainsource);

	printf("BFS sequence is :\n ");
	do
	{
		front = 0;
		rear = -1;
		visitcount = visitcount + bfs(mainsource);
		if (visitcount != n)
		{
			printf("\n\t\t BFS initiated with new source because graph is disconnected \n");
			for (i = 0; i < n; i++)
			{
				if (bit[i] == 0)
					break;
			}
			mainsource = i;
		}
		else
			break;
	} while (1);

	// printf("\n shortest paths to vertices are as below: \n");
	// for (i = 0; i < n; i++)
	// {
	// 	printf("destination=%d path= ", i);
	// 	printshortestpathto(i);
	// 	printf("\n");
	// }
	return 0;
}

int bfs(int source)
{
	int dequeuedvertex;
	int i, adjacentnode;
	int touchcount;

	rear++;
	Q[rear] = source;
	bit[source] = 1; // parent[source]=-1;
	touchcount = 1;

	do
	{
		dequeuedvertex = Q[front];
		front++;
		i = 0;
		printf("%d ", dequeuedvertex);
		adjacentnode = VAL[dequeuedvertex][i];
		while (adjacentnode != -1)
		{
			if (bit[adjacentnode] == 0)
			{
			//	printf("%d ", adjacentnode);
				rear++;
				Q[rear] = adjacentnode;
				bit[adjacentnode] = 1;
				// parent[adjacentnode]=dequeuedvertex;
				touchcount++;
			}
			i++;
			adjacentnode = VAL[dequeuedvertex][i];
		}
	} while (front != rear);
	printf("%d",Q[rear]);
	return touchcount;
}

// void printshortestpathto(int destination)
// {
// 	while(destination != -1)
// 	{
// 		printf("%d ", destination);
// 		destination=parent[destination];
// 	}
// }