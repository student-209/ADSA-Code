#include <stdio.h>
#include <stdlib.h>
int knapsack(int, int);
int max(int, int);
int p[20], w[20], n;

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int knapsack(int i, int capacity)
{
    if (i == n)
    {
        return (w[n] > capacity ? 0 : p[i]);
    }

    if (w[i] > capacity)
    {
        return knapsack(i + 1, capacity);
    }

    return max((i + 1, capacity), (i + 1, capacity - w[i]) + p[i]);
}

int main()
{

    int i, j, capacity, temp;
    float p[20], w[20], ratio[20];

    printf("Enter the number of the objects:");
    scanf("%d", &n);
    printf("Enter the weight:");
    for (i = 1; i <= n; i++)
    {
        scanf("%f", &w[i]);
    }

    for (i = 1; i <= n; i++)
    {
        scanf("%f", &p[i]);
    }

    printf("Enter the capacity:");
    scamf("%d", &capacity);

    int optSoln = knapsack(1, capacity);

    printf("The max profit is: %f", optSoln);

    return 0;
}