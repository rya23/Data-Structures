#include<stdio.h>
#include<malloc.h>

char * bit;
int *parent;
int ** VAL;
int n;
int mainsource;
int visitcount;

void dfs(int );

int main()
{
	int i,ac,j;
    
	printf("Enter the number of vertices: ");
	scanf("%d", &n);
	VAL=(int **)malloc(n*sizeof(int*));
	bit=(char*)calloc(n,sizeof(char));
	parent=(int *)malloc(n*sizeof(int));

	for(i=0;i<n;i++)
	{
		printf("How many vertices adjacent to vertex %d ?", i);
		scanf("%d", &ac);
		VAL[i]=(int*)malloc((ac+1)*sizeof(int));

		printf("Enter names of %d adjacent vertices: ", ac);
		for(j=0;j<ac;j++)
		{
			scanf("%d", &VAL[i][j]);
		}
		VAL[i][j]=-1;
	}

	printf("Enter the source vertex: ");
	scanf("%d", &mainsource);

	printf("DFS sequence is :\n ");
	do
	{
		printf("%d ", mainsource);
		bit[mainsource]=1; parent[mainsource]=-1; visitcount++;
		dfs(mainsource);
		if( visitcount !=n)
		{
			for(i=0;i<n;i++)
			{
				if(bit[i]==0)
					break;
			}
			mainsource=i;
			printf("\n\t\t DFS initiated with new source $ %d $because graph is disconnected \n", mainsource);
		}
		else
			break;
	}while( 1 );

	return 0;
}

void dfs(int x)
{
	int adjacent;
	int i=0;
	adjacent=VAL[x][i];
	while(adjacent!=-1)
	{
		if(bit[adjacent]==0)
		{
			visitcount++;
			printf("%d ", adjacent);
			bit[adjacent]=1;
			parent[adjacent]=x;
			dfs(adjacent);
		}
		i++;
	        adjacent=VAL[x][i];	
	}
}

