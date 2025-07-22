
void BFS(int a[MAX][MAX], int source, int visited[MAX], int n)
{
    int f, r, u, v;
    int queue[MAX];
    f = 0;
    r = -1;
    queue[++r] = source;
    while (f <= r)