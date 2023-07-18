#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

    double bubble_sort_runtime = (double)(bubble_sort_end_time - start_time) / CLOCKS_PER_SEC * 1000000;
    printf("\nBubble Sort Runtime: %.6f microseconds\n", bubble_sort_runtime);

    return 0;
}
