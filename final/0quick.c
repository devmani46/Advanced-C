#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int p = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < p) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(int argc, char const* argv[])
{
    int* arr;
    int size;
    printf("Enter Size of array: ");
    scanf("%d", &size);
    arr = malloc(sizeof(int) * size);

    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int randomNum = (rand() % size) + 1;
        int duplicateEle = 0;
        for (int j = 0; j < i; j++) {
            if (arr[j] == randomNum) {
                duplicateEle = 1;
                break;
            }
        }
        if (duplicateEle == 0) {
            arr[i] = randomNum;
        }
        else {
            i--;
        }
    }

    printf("The randomly generated elements are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    clock_t start_time = clock();

    quickSort(arr, 0, size - 1);

    clock_t quick_sort_end_time = clock();

    printf("\nThe elements sorted using Quick Sort are:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    double quick_sort_runtime = (double)(quick_sort_end_time - start_time) / CLOCKS_PER_SEC * 1000000;
    printf("\nQuick Sort Runtime: %.6f microseconds\n", quick_sort_runtime);

    return 0;
}
