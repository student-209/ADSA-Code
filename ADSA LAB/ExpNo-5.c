#include <stdio.h>
#include <stdlib.h>
#define MAX 50
void DFS(int[MAX][MAX], int, int visited[MAX], int);
void main()
{
    printf("Name:Rutuja Dundesh Mane\nPRN:2324000718\nDiv:A\nRoll No:44\n");
    printf("-----------------------------------------\n");
    int n, a[MAX][MAX], i, j, visited[MAX], source;

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
void DFS(int a[MAX][MAX], int u, int visited[MAX], int n)
{
    int v;
    visited[u] = 1;
    for (v = 1; v <= n; v++)
    {
        if (a[u][v] == 1 && visited[v] == 0)
            DFS(a, v, visited, n);
    }
}
