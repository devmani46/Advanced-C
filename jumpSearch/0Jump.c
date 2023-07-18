#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int jump_search(int arr[], int size, int target)
{
    int step = sqrt(size);
    int a = 0;

    while (arr[min(step, size) - 1] < target)
    {
        a = step;
        step += sqrt(size);
        if (a >= size)
            return -1;
    }

    while (arr[a] < target)
    {
        a++;
        if (a == min(step, size))
            return -1;
    }

    if (arr[a] == target)
        return a;

    return -1;
}

void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int *arr;
    int size;
    printf("Enter Size of array: ");
    scanf("%d", &size);
    arr = malloc(sizeof(int) * size);

    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        int randomNum = (rand() % size) + 1;
        int duplicateEle = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] == randomNum)
            {
                duplicateEle = 1;
                break;
            }
        }
        if (duplicateEle == 0)
        {
            arr[i] = randomNum;
        }
        else
        {
            i--;
        }
    }

    printf("The randomly generated elements are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    clock_t start_time = clock();

    bubbleSort(arr, size);

    clock_t bubble_sort_end_time = clock();

    printf("\nThe elements sorted using Bubble Sort are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    int target;
    printf("\nEnter Target Element: ");
    scanf("%d", &target);

    clock_t jump_search_start_time = clock();

    int index = jump_search(arr, size, target);

    clock_t jump_search_end_time = clock();
    if (index != -1)
    {
        printf("Element %d found at index %d.\n", target, index);
    }
    else
    {
        printf("Element %d not found in the array.\n", target);
    }

    double bubble_sort_runtime = (double)(bubble_sort_end_time - start_time) / CLOCKS_PER_SEC * 1000000;
    double jump_search_runtime = (double)(jump_search_end_time - jump_search_start_time) / CLOCKS_PER_SEC * 1000000;
    printf("Bubble Sort Runtime: %.6f microseconds\n", bubble_sort_runtime);
    printf("Jump Search Runtime: %.6f microseconds\n", jump_search_runtime);

    return 0;
}
