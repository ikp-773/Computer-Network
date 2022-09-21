// Exp 8 Distance Vector Routing


#include<stdio.h>
#include<stdlib.h>

struct node
{
	unsigned dist[20];
	unsigned from[20];
} rt[10];

void main()
{
	int costmat[20][20];
	int nodes,i,j,k,count =0;

	printf("\nEnter the no of nodes: ");
	scanf("%d",&nodes);

	printf("\nEnter the cost matrix: ");
	
	for(i=0;i<nodes;i++)
	{
		for(j=0;j<nodes;j++)
		{
			scanf("%d",&costmat[i][j]);
			costmat[i][i] = 0;
			rt[i].dist[j] = costmat[i][j];
			rt[i].from[j] = j;
		}
	}

	do
	{
		count =0;
		for(i=0;i<nodes;i++)
		for(j=0;j<nodes;j++)
		for(k=0;k<nodes;k++)
		{
			if (rt[i].dist[j] > costmat[i][k] + rt[k].dist[j] )
			{	
				rt[i].dist[j] = rt[i].dist[k] + rt[k].dist[j];
				rt[i].from[j] = k;
				count++;
			}	 
		}	
	} while(count!=0);

	for(i=0;i<nodes;i++)
	{
		printf("\n\n For router %d \n", i+1);
		
		for(j=0;j<nodes;j++)
		{
			printf("\t\n Node %d Via %d Distance %d", j+1,rt[i].from[j]+1, rt[i].dist[j]);
		}
	}

	printf("\n\n");
}


/* OUTPUT

Enter the no of nodes: 3

Enter the cost matrix: 0 2 7 2 0 1 7 1 0


 For router 1 
	
 Node 1 Via 1 Distance 0	
 Node 2 Via 2 Distance 2	
 Node 3 Via 3 Distance 3

 For router 2 
	
 Node 1 Via 1 Distance 2	
 Node 2 Via 2 Distance 0	
 Node 3 Via 3 Distance 1

 For router 3 
	
 Node 1 Via 1 Distance 3	
 Node 2 Via 2 Distance 1	
 Node 3 Via 3 Distance 0

*/
