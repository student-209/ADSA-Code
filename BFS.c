/*Print all the nodes reachable from a given starting node in a digraph using BFS
method.*/
#include <stdio.h>
#define MAX 20
void BFS(int[MAX][MAX], int, int[MAX], int);
void main()
{
    int n, a[MAX][MAX], i, j, visited[MAX], source;
    printf("Enter the number of vertices:");
    scanf("%d", &n);
    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &a[i][j]);
    for (i = 1; i <= n; i++)
        visited[i] = 0;
    printf("\nEnter the source node:");
    scanf("%d", &source);
    visited[source] = 1;
    BFS(a, source, visited, n);
    for (i = 1; i <= n; i++)
    {
        if (visited[i] != 0)
            printf("\n Node %d is reachable", i);
        else
            printf("\n Node %d is not reachable", i);
    }
}
void BFS(int a[MAX][MAX], int source, int visited[MAX], int n)
{
    int queue[MAX], f, r, u, v;
    f = 0;
    r = -1;
    queue[++r] = source;
    while (f <= r)
    {
        u = queue[f++];
        for (v = 1; v <= n; v++)
        {
            if (a[u][v] == 1 && visited[v] == 0)
            {
                queue[++r] = v;
                visited[v] = 1;
            }
        } // for v
    } // while
}

// Another way

// #include <stdio.h>
// #define MAX 20

// void BFS(int adj[MAX][MAX], int visited[MAX], int start, int n)
// {
//     int queue[MAX], front = 0, rear = 0;
//     queue[rear++] = start;
//     visited[start] = 1;

//     printf("BFS Traversal: ");
//     while (front < rear)
//     {
//         int current = queue[front++];
//         printf("%d ", current);

//         for (int i = 0; i < n; i++)
//         {
//             if (adj[current][i] == 1 && visited[i] == 0)
//             {
//                 queue[rear++] = i;
//                 visited[i] = 1;
//             }
//         }
//     }
//     printf("\n");
// }

// int main()
// {
//     int n, adj[MAX][MAX], visited[MAX] = {0}, start;

//     printf("Enter the number of nodes: ");
//     scanf("%d", &n);

//     printf("Enter the adjacency matrix:\n");
//     for (int i = 0; i < n; i++)
//         for (int j = 0; j < n; j++)
//             scanf("%d", &adj[i][j]);

//     printf("Enter the starting node: ");
//     scanf("%d", &start);

//     BFS(adj, visited, start, n);

//     return 0;
// }
