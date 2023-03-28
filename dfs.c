// to implement dfs on given graph
// using recursion so as to use implicit stack i.e. recursive function call stack
#include <stdio.h>
#include <stdlib.h>
void dfs(int[5], int[5][5], int);
void main()
{
    char node;
    int visited[5] = {0, 0, 0, 0, 0};
    int adj[5][5] = {
        {0, 1, 1, 1, 1},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {1, 0, 1, 0, 0}
        };
    printf("\nChoose a node to begin with: ");
    scanf("%c", &node);
    dfs(visited, adj, ((int)node)-65);
} // end of main
void dfs(int visited[5], int adj[5][5], int node)
{
    int j;
    visited[node] = 1;
    printf("%c ", (char)(node+65));
    for (j = 0; j < 5; j++)
    {
        if (adj[node][j] && !visited[j])
            dfs(visited, adj, j);
    } // end of for loop
} // end of fn.
