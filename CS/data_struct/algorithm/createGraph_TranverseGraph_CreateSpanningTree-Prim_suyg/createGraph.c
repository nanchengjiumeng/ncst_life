#include "Graph.h"
#include "Queue.h"

void CreateMGraph(MGraph *G)
{
	int i,j,k,w;

//imput the Graph from the Command Wiondow.
//********************************************************************************************************
//  printf("Please input the count of vertex and edge!\n");
//	scanf("%d,%d",&G->numVertexes,&G->numEdges);
//	getchar();                             /*deal with the carriage return*/
//	printf("Please input the vertexes one by one!\n");
//	for(i=0;i < G->numVertexes;i++)        /*intput the Value of the Vertex, create he Vertex array*/
//	{
//		scanf("%c",&G->vexs[i]);
//	}
//	for(i=0;i<G->numVertexes;i++)          /*initialize the adjacency Matrix*/
//	{
//		for(j=0;j<G->numVertexes;j++)
//		{
//			G->arc[i][j] = INFINITY;
//		}
//	}
//	for(k = 0;k<G->numEdges;k++)           /*assign the adjacency Matrix*/
//	{
//		printf("Please input the subscript (i,j) of the edge (Vi,Vj), as well as the weight of the edge.\n");
//		scanf("%d,%d,%d",&i,&j,&w);
//		G->arc[i][j] = w;
//		G->arc[j][i] = G->arc[i][j];
//	}
//**********************************************************************************************	


//Create a Graph with a supported Matrix and vertex array 
//**********************************************************************************************
	//initialize a Graph
	G->numVertexes = 9;
	for(i = 0; i < G->numVertexes;i++)
	{
		G->vexs[i] = 'a' + i;
	}
	G->numEdges = 14;
	EdgeType arcArray[9][9] =                                                                 //这里如果采用变量可能产生变量不被初始化的错误所以不能编译 
		{    /* 0 */  /* 1 */  /* 2 */  /* 3 */  /* 4 */  /* 5 */  /* 6 */  /* 7 */  /* 8 */
	/*0*/	{INFINITY,      10,INFINITY,INFINITY,INFINITY,      11,INFINITY,INFINITY,INFINITY},
			
	/*1*/	{      10,INFINITY,      18,INFINITY,INFINITY,INFINITY,      16,INFINITY,      12},
			
	/*2*/	{INFINITY,      18,INFINITY,      22,INFINITY,INFINITY,INFINITY,INFINITY,       8},
			
	/*3*/	{INFINITY,INFINITY,      22,INFINITY,      20,INFINITY,INFINITY,      16,      21},
			
	/*4*/	{INFINITY,INFINITY,INFINITY,      20,INFINITY,      26,INFINITY,       7,INFINITY},
			
	/*5*/	{      11,INFINITY,INFINITY,INFINITY,      26,INFINITY,      17,INFINITY,INFINITY},
			
	/*6*/	{INFINITY,      16,INFINITY,INFINITY,INFINITY,      17,INFINITY,      19,INFINITY},
			
	/*7*/	{INFINITY,INFINITY,INFINITY,      16,       7,INFINITY,      19,INFINITY,INFINITY},
			
	/*8*/	{INFINITY,      12,       8,      21,INFINITY,INFINITY,INFINITY,INFINITY,INFINITY},
		};
	
	for(i = 0;i<G->numVertexes;i++)
	{
		for(j= 0;j<G->numVertexes;j++)
		{
			G->arc[i][j] = arcArray[i][j];
		}
	}	 
//********************************************************************************************************
}

void PrintMGraph(MGraph G)
{
	int i,j;
	printf("The Vertex array is : \n");  /*print the vertex array*/
	for (i=0;i<G.numVertexes;i++)
	{
		printf("  %c",G.vexs[i]);
	}
	printf("\n");
	printf("The adjancency Matrix is:\n");  /*print the Matrix*/
	for (i=0;i<G.numVertexes;i++)
	{
		for(j=0;j<G.numVertexes;j++)
		{
			if (i==j)
				printf("%6s","0");
			else if (G.arc[i][j] == INFINITY)
				printf("%6s","IF");
			else 
				printf("%6d",G.arc[i][j]);
		}
		printf("\n");
	}
}

void DFS(MGraph G,int i)   //DFS begin with the ith vertex
{
	int j;
	visited[i] = TRUE;
	printf("%c ",G.vexs[i]);
	for(j = 0;j<G.numVertexes;j++)
	{
		if(G.arc[i][j] != INFINITY && !visited[j])
		{
			DFS(G,j);
		}
	}
}
void DFSTranverse(MGraph G)
{
	int i;
	printf("The DFS sequence is:\n");
	for(i=0;i<G.numVertexes;i++)
	{
		visited[i] = FALSE;
	}
	for(i=0;i<G.numVertexes;i++)
	{
		if(!visited[i])
		{
			DFS(G,i);
		}
	}
	printf("\n");
}

void BFSTranverse(MGraph G)
{
	int i,j;
	Queue Q;
	printf("The BFS sequence is:\n");
	for(i=0;i<G.numVertexes;i++)
	{
		visited[i]=FALSE;
	}
	InitQueue(&Q);
	for(i=0;i<G.numVertexes;i++)
	{
		if(!visited[i])
		{
			visited[i]=TRUE;
			printf("%c ",G.vexs[i]);
			EnQueue(&Q,i);
			while(!QueueEmpty(Q))
			{
				DeQueue(&Q,&i);
				for(j=0;j<G.numVertexes;j++)
				{
					if(G.arc[i][j] != INFINITY && !visited[j])
					{
						visited[j] = TRUE;
						printf("%c ",G.vexs[j]);
						EnQueue(&Q,j);
					}
				}
			}
		}
	}
	printf("\n");
}

void MiniSpanTree_Prim(MGraph G)
{
	int min,i,j,k;
	int adjvex[MAXVEX];
	int lowcost[MAXVEX];
	lowcost[0] = 0 ;
	adjvex[0] =0;
	printf("The minimum spanning tree is (Prim):\n");
	for(i = 1;i<G.numVertexes;i++)
	{
		lowcost[i] = G.arc[0][i];
		adjvex[i] = 0;
	}
	
	for(i =1;i<G.numVertexes;i++)
	{
		min = INFINITY;
		j=1;k=0;
		while(j<G.numVertexes)
		{
			if(lowcost[j]!=0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k=j;
			}
			j++;
			
		}
		//printf("(%d,%d)",adjvex[k],k);
		printf("(%c,%c)",G.vexs[adjvex[k]],G.vexs[k]);
		lowcost[k] = 0;
		for(j =1;j<G.numVertexes;j++)
		{
			if ((lowcost[j]!=0) && (G.arc[k][j]<lowcost[j]))
			{
				lowcost[j] = G.arc[k][j];
				adjvex[j] = k ;
			}
		}
	}
	printf("\n");
}

int Find(int *parent,int f)
{
	while(parent[f]>0)
	{
		f = parent[f];
	}
	return f;
}


void MiniSpanTree_Kruskal(MGraph G)
{
	int i,j,n,m,k;
	Edge edges[G.numEdges];
	int parent[G.numVertexes];
	
	//******************adjacency Matrix to Edges Array********************
	k=0;
	for(i=0;i<G.numVertexes;i++)
	{
		for(j=(i+1);j<G.numVertexes;j++)    /*undigraph just deal with upper triangle Matrix*/
		{
			if (G.arc[i][j]!=INFINITY)
			{
				edges[k].weight = G.arc[i][j];
				edges[k].begin = i;
				edges[k].end = j;
				k++;	
			}	
		}
	}
	//******************adjacency Matrix to Edges Array******************** 
	//print the edge array.
	//for(i=0;i<G.numEdges;i++)
//	{
//		printf("edge[%d]: begin: %d, end: %d, weight: %d \n",i,edges[i].begin,edges[i].end,edges[i].weight);
//	}
	
	//************sort the edges array with bubble sorting method**********
	Edge temp;
	for(k=1;k<=G.numEdges-1;k++)
	{
		for(i=0;i<G.numEdges-k;i++)
		{
			if (edges[i].weight>edges[i+1].weight)
			{
				temp = edges[i];
				edges[i] = edges[i+1];
				edges[i+1] = temp;
			}
			
		}	
	}
	
	//print the ordered edge array
	//for(i=0;i<G.numEdges;i++)
//	{
//		printf("edge[%d]: begin: %d, end: %d, weight: %d \n",i,edges[i].begin,edges[i].end,edges[i].weight);
//	}	
	//************sort the edges array with bubble sorting method**********
	
	for(i = 0; i<G.numVertexes;i++)
	{
		parent[i] = 0;
	}
	printf("The minimum spanning tree is (Kruskal):\n");
	for(i = 0; i<G.numEdges;i++)
	{
		n=Find(parent,edges[i].begin);
		m=Find(parent,edges[i].end);
		if(n!=m)
		{
			parent[n] = m;
			printf("[(%c,%c) %d] ",G.vexs[edges[i].begin],G.vexs[edges[i].end],edges[i].weight);
		}
	}
	printf("\n");	
}

int main()
{
	MGraph G;
	CreateMGraph(&G);
	PrintMGraph(G);	
	DFSTranverse(G);
	BFSTranverse(G);
	MiniSpanTree_Prim(G);
	MiniSpanTree_Kruskal(G);
	getchar();
	return 0;
}
