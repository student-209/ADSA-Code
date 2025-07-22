#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by value-to-weight ratio in descending order
void sortByRatio(int n, int weights[], int values[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            float r1 = (float)values[j] / weights[j];
            float r2 = (float)values[j + 1] / weights[j + 1];
            if (r1 < r2)
            {
                swap(&weights[j], &weights[j + 1]);
                swap(&values[j], &values[j + 1]);
            }
        }
    }
}

// Function to calculate the maximum value for the Fractional Knapsack problem
float fractionalKnapsack(int n, int weights[], int values[], int capacity)
{
    sortByRatio(n, weights, values);

    float totalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (weights[i] <= capacity)
        {
            // If the item can be fully included
            capacity -= weights[i];
            totalValue += values[i];
        }
        else
        {
            // Take the fractional part if the item can't be fully included
            totalValue += values[i] * ((float)capacity / weights[i]);
            break; // Knapsack is now full
        }
    }

    return totalValue;
}

int main()
{
    int n, capacity;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weights[n], values[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &weights[i], &values[i]);
    }

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    float totalProfit = fractionalKnapsack(n, weights, values, capacity);

    printf("Total profit of the knapsack = %.2f\n",totalProfit );

    return 0;
}
