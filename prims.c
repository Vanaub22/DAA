//to find MST from given graph using Prim's Algorithm
#include<stdio.h>
#include<stdbool.h>
#include<limits.h>
#define V 9
void prims(int graph[V][V]);
int minkey(int* key,bool* MST_check);
void display(int parent[],int graph[V][V]);
void prims(int graph[V][V]){
	int v,u,i,count,parent[V],key[V];
	bool MST_check[V];
	for(i=0;i<V;i++){
		key[i]=INT_MAX;
		MST_check[i]=false;
	}//end of for loop
	key[0]=0;
	parent[0]=-1;
	for(count=0;count<V-1;count++){
	u=minkey(key,MST_check);
	MST_check[u]=true;
	for(v=0;v<V;v++)
	if(graph[u][v] && !MST_check[v] && graph[u][v]<key[v]){
	parent[v]=u;
	key[v]=graph[u][v];
	}//end of if block
	}//end of outer for loop
	display(parent,graph);
}//end of fn.
int minkey(int* key,bool* MST_check){
	int min=INT_MAX,min_index,v;
	for(v=0;v<V;v++)
	if(!MST_check[v] && key[v]<min){
		min=key[v];
		min_index=v;
	}//end of if block
	return(min_index);
}//end of fn.
void display(int parent[],int graph[V][V]){
	printf("\nThe MINIMUM SPANNING TREE will be as follows:\n\n");
	int i;
	printf("Edge\tWeight\n");
	for(i=1;i<V;i++){
		printf("%c-%c\t%d\n",(char)(parent[i]+97),(char)(i+97),graph[i][parent[i]]);
	}//end of for loop
}//end of fn.
void main(){
	int graph[V][V]={{0,4,0,0,0,0,0,8,0},
			{4,0,8,0,0,0,0,11,0},
			{0,8,0,7,0,4,0,0,2},
			{0,0,7,0,9,14,0,0,0},
			{0,0,0,9,0,10,0,0,0},
			{0,0,4,14,10,0,2,0,0},
			{0,0,0,0,0,2,0,1,6},
			{8,11,0,0,0,0,1,0,7},
			{0,0,2,0,0,0,6,7,0}};
	prims(graph);	
}//end of main












