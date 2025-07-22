#include <stdio.h>
#include <stdlib.h>
#define MAX 20
void BFS(int a[MAX][MAX], int, int visited[MAX], int n);
int main()
{
    int a[MAX][MAX], i, j, n, source, visited[MAX];
    printf("Enter the number of vertices\n:");
    scanf("%d", &n);

    printf("Enter the adjuncenecy matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i <= n; i++)
    {
        visited[i] = 0;
    }

    printf("Enter the source vertex:\n");
    scanf("%d", &source);

    visited[source] = 1;
    BFS(a, source, visited, n);

    if (visited[i] != 0)
    {
        printf("\nnode %d is reachavle", i);
    }
    else
    {
        printf("\nnode %d is not raechavle ", i);
    }
}

void BFS(int a[MAX][MAX], int source, int visited[MAX], int n)
{
    int f, r, u, v;
    int queue[MAX];
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
