#include <stdio.h>
void knapsack(int n, float weight[], float profit[], float capacity)
{
    float x[20], totalProfit = 0;
    int i, j, u;
    u = capacity;

    for (i = 0; i < n; i++)
    {

        x[i] = 0.0;
    }

    for (i = 0; i < n; i++)
    {
        if (weight[i] > u)
            break;
        else
        {
            x[i] = 1.0;
            totalProfit = totalProfit + profit[i];
            u = u - weight[i];
        }
    }

    if (i < n)
    {

        x[i] = u / weight[i];
        totalProfit = totalProfit + (x[i] * profit[i]);
    }

    printf("The result vector is:");
    for (i = 0; i < n; i++)
    {

        printf("%f\t", x[i]);
    }
    printf("\nMaximum profit is: %f", totalProfit);
}
int main()
{

    printf("Name:Rutuja Dundesh Mane\nPRN:2324000718\nDiv:A\nRoll No:44\n");
    printf("-----------------------------------------\n");

    float weight[20], profit[20], capacity;
    int num, i, j;
    float ratio[20], temp;
    printf("enter the number of objects: ");
    scanf("%d", &num);
    printf("Enter the weights and profoits of each objects:\n");
    for (i = 0; i < num; i++)
    {
        scanf("%f%f", &weight[i], &profit[i]);
    }

    printf("Enter the capacity if the knapsack:");
    scanf("%f", &capacity);

    for (i = 0; i < num; i++)
    {
        ratio[i] = profit[i] / weight[i];
    }

    for (i = 0; i < num; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = weight[j];
                weight[j] = weight[i];
                weight[i] = temp;

                temp = profit[j];
                profit[j] = profit[i];
                profit[i] = temp;
            }
        }
    }

    knapsack(num, weight, profit, capacity);

    return 0;
}