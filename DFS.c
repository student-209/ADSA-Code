
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void DFS(int[MAX][MAX], int, int[20], int);
void main()
{
    int n, a[20][20], i, j, visited[20], source;
    int clrscr();
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)

        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    printf("\nEnter the source node: ");

    scanf("%d", &source);
    DFS(a, source, visited, n);
    for (i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            printf("\nGraph is not connected");
            exit(0);
        }
    }
    printf("\nGraph is connectd\n");
}
void DFS(int a[20][20], int u, int visited[20], int n)
{
    int v;
    visited[u] = 1;
    for (v = 1; v <= n; v++)
    {
        if (a[u][v] == 1 && visited[v] == 0)
            DFS(a, v, visited, n);
    }
}

// Another way
// #include <stdio.h>
// #define MAX 20

// void DFS(int adj[MAX][MAX], int visited[MAX], int current, int n) {
//     visited[current] = 1;
//     printf("%d ", current);

//     for (int i = 0; i < n; i++) {
//         if (adj[current][i] == 1 && visited[i] == 0) {
//             DFS(adj, visited, i, n);
//         }
//     }
// }

// int main() {
//     int n, adj[MAX][MAX], visited[MAX] = {0}, start;

//     printf("Enter the number of nodes: ");
//     scanf("%d", &n);

//     printf("Enter the adjacency matrix:\n");
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             scanf("%d", &adj[i][j]);

//     printf("Enter the starting node: ");
//     scanf("%d", &start);

//     printf("DFS Traversal: ");
//     DFS(adj, visited, start, n);
//     printf("\n");

//     return 0;
// }
