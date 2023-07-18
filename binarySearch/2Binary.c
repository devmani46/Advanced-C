#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isDuplicate(int arr[], int index, int value)
{
    for (int i = 0; i < index; i++)
    {
        if (arr[i] == value)
            return 1;
    }
    return 0;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main(int argc, char const *argv[]) {
int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int randomNum;
        do
        {
            randomNum = rand() % 100;
        } while (isDuplicate(arr, i, randomNum));
        arr[i] = randomNum;
    }

    printf("Randomly Generated elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start_time = clock();

    bubbleSort(arr, n);

    clock_t bubble_sort_end_time = clock();

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);

    clock_t binary_search_start_time = clock();

    int index = binarySearch(arr, 0, n - 1, target);

    clock_t binary_search_end_time = clock();
    if (index != -1)
    {
        printf("Element %d found at index %d.\n", target, index);
    }
    else
    {
        printf("Element %d not found in the array.\n", target);
    }

    double bubble_sort_runtime = (double)(bubble_sort_end_time - start_time) / CLOCKS_PER_SEC*1000000;
    double binary_search_runtime = (double)(binary_search_end_time - binary_search_start_time) / CLOCKS_PER_SEC*1000000;
    printf("Bubble Sort Runtime: %.6f microseconds\n", bubble_sort_runtime);
    printf("Binary Search Runtime: %.6f microseconds\n", binary_search_runtime);

    return 0;
}
