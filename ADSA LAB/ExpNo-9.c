#include <stdio.h>
#define MAX 50

int p[MAX], w[MAX], n;
int knapsack(int, int);
int max(int, int);

int main()
{

    int capacity, i, optsoln;
    printf("Enter the number of objects:");
    scanf("%d", &n);
    printf("\nEnter the weights:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }

    printf("\nEnter the profits:\n");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    printf("\nEnter the knapsack capcity:");
    scanf("%d", &capacity);

    optsoln = knapsack(1, capacity);

    printf("\nThe optimal solution is:%d", optsoln);
}

int knapsack(int i, int capacity)
{
    if (i == n)
    {
        return (w[n] > capacity) ? 0 : p[n];
    }

    if (w[i] > capacity)
    {
        return knapsack(i + 1, capacity);
    }

    return max(knapsack(i + 1, capacity), knapsack(i + 1, capacity - w[i]) + p[i]);
}

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