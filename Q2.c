#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[low]; // Choosing the first element as the pivot
    int i = low + 1;      // Starting index for elements greater than pivot

    for (int j = low + 1; j <= high; j++)
    {
        // If the current element is smaller than or equal to the pivot
        if (arr[j] < pivot)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }            
    }
    swap(&arr[low], &arr[i - 1]); // Place pivot in correct position
    return (i - 1);               // Return the partitioning index
}

// Function to implement quicksort
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // Partitioning index
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int n;

    // Input size of the array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input elements of the array
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Given array is: ");
    printArray(arr, n);

    // Call quickSort on the array
    quickSort(arr, 0, n - 1);

    printf("Sorted array is: ");
    printArray(arr, n);

    return 0;
}
