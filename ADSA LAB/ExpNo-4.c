#include <stdio.h>
#define MAX 20
void BFS(int[MAX][MAX], int, int[MAX], int);
int main()
{
    printf("Name:Rutuja Dundesh Mane\nPRN:2324000718\nDiv:A\nRoll No:44\n");
    printf("-----------------------------------------\n");
    int n, a[MAX][MAX], i, j, visited[MAX], source;

    printf("Enter the number of vertices:");
    scanf("%d", &n);

    printf("\nEnter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
    {
        visited[i] = 0;
    }

    printf("\nEnter the source node:");
    scanf("%d", &source);

    visited[source] = 1;

    BFS(a, source, visited, n);

    for (i = 1; i <= n; i++)
    {
        if (visited[i] != 0)
        {
            printf("\n Node %d is reachable", i);
        }
        else
        {
            printf("\n Node %d is not reachable", i);
        }
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
        }
    }
}
