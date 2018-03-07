/*
This function implement the creation of a Graph which is stored in a adjacency matrix.
The testing data is: (9 vertexes 14 edges)
9,14    
abcdefghi     //vertexes information
(0,1,10)      //edge which is indicated by the format of (Vertex i, Vertex j, weight)
(0,5,11)
(1,2,18)
(1,6,16)
(1,8,12)
(2,3,22)
(2,8,8)
(3,4,20)
(3,7,16)
(3,8,21)
(4,5,26)
(4,7,7)
(5,6,17)
(6,7,19)
*/

#define MAXVEX 100
#define INFINITY 65535
#define TRUE 1
#define FALSE 0
typedef char VertexType;
typedef int EdgeType;
typedef int Boolean;
typedef struct MGraph
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;	
}MGraph;

Boolean visited[MAXVEX];         /*Indicates the vertex has been visited or not*/


typedef struct Edge              /*struct for implementing graph with the method of "±ß¼¯Êý×é"*/
{
	int begin;
	int end;
	int weight;
}Edge;
