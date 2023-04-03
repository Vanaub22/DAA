//to find Minimum Spanning Tree (MST) for given graph using Kruskal's Algorithm (Greedy Approach)
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<stdbool.h>
#define V 6
int i,j,k,a,b,u,v,ne=1,min,minimum_cost=0,parent[V];
//implemented using Adjacency Matrix
int Adj[V][V]={
        {0,5,4,6,2,0},
        {5,0,0,2,0,3},
        {4,0,0,0,3,0},
        {6,2,0,0,1,2},
        {2,0,3,1,0,4},
        {0,3,0,2,4,0}
        };
int findParent(int i){
    while(parent[i])
    i=parent[i];
    return(i);
}//end of fn.
bool modifyParent(int i,int j){
    if(i!=j)
    parent[j]=i;
    return(i!=j);
}//end of fn.
void main(){
    for(i=0;i<V;i++)
    for(j=0;j<V;j++)
    if(Adj[i][j]==0)
    Adj[i][j]=INT_MAX;
    printf("The Edges of the Minimum Spanning Tree (MST) by Kruskal's Algorithm is as follows:");
    while(ne<V){
        for(i=0,min=INT_MAX;i<V;i++)
        for(j=0;j<V;j++){
            if(Adj[i][j]<min){
                min=Adj[i][j];
                a=u=i;
                b=v=j;
            }//end of if block
        }//end of for loop
        u=findParent(u);
        v=findParent(v);
        if(modifyParent(u,v)){
            printf("\nEdge %d: < %c - %c > | Cost: %d",ne++,(char)(a+65),(char)(b+65),min);
            minimum_cost+=min;
        }//end of if block
        Adj[a][b]=Adj[b][a]=INT_MAX;
    }//end of while loop    
    printf("\nThe Minimum Cost to travel all the vertices is %d",minimum_cost);
}//end of main