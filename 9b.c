
#include <stdio.h>
#include <stdlib.h>

#define MAX 100  
int visited[MAX]; 
int adj[MAX][MAX];
int n; 


void DFS(int v) {
    visited[v] = 1; 
    for (int i = 0; i < n; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1; 
    }

    
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    
    DFS(0);

    
    
    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            connected = 0;
            break;
        }
    }

    if (connected)
        printf("Graph is Connected\n");
    else
        printf("Graph is Not Connected\n");

    return 0;
}
