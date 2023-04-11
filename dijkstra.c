//to find single-source-shortest-path result by Dijkstra's Algorithm for a given graph
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#define V 5
void dijkstra(int[V][V],int);
int nearest(int*,bool*);
void main()
{
	int src,graph[V][V]={{0,5,2,10,6},{5,0,13,4,0},{2,13,0,9,3},{10,4,9,0,4},{6,0,3,4,0}};
	printf("Enter the source: ");
	scanf("%d", &src);
	printf("\nDIJKSTRA'S ALGORITHM\n");
	printf("RESULT for Minimum Cost Path to all the vertices from Source Vertex %d",src);
	dijkstra(graph, src-1);
}//end of main
int nearest(int dist[], bool Visited[]){
	int v,min=INT_MAX,min_index;
	for (v=0;v<V;v++)
		if(Visited[v]==false&&dist[v]<=min)
		min=dist[v],min_index=v;
	return(min_index);
}//end of fn.
void dijkstra(int graph[V][V], int src){
	int dist[V],i,v,u;
	bool Visited[V];
	for(i=0;i<V;i++)
	dist[i]=INT_MAX;
	Visited[i]=false;
	dist[src]=0;
	int count;
	for(count=0;count<V-1;count++) 
	{
		u=nearest(dist, Visited);
		Visited[u]=true;
		for(v=0;v<V;v++)
		if(!Visited[v] && graph[u][v] && dist[u]!=INT_MAX && (dist[u]+graph[u][v])<dist[v])
		dist[v]=dist[u]+graph[u][v];
	}
	printf("\nVertex\t\tCost\n");
	for(i=0;i<V;i++)
	printf("%d\t\t%d\n",i+1,dist[i]);
}//end of fn.

