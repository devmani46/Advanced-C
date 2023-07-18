#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

int recursiveInterpolationSearch(int arr[], int low, int high, int target) {
    if (low <= high && target >= arr[low] && target <= arr[high]) {
        int pos = low + ((target - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (target == arr[pos])
            return pos;
        else if (target < arr[pos])
            return recursiveInterpolationSearch(arr, low, pos - 1, target);
        else
            return recursiveInterpolationSearch(arr, pos + 1, high, target);
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;
    }

    printf("Generated elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    clock_t start_time = clock();

    bubbleSort(a, n);

    clock_t bubble_sort_end_time = clock();

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int search;
    printf("Enter the number to search: ");
    scanf("%d", &search);

    clock_t interpolation_search_start_time = clock();

    int index = recursiveInterpolationSearch(a, 0, n - 1, search);

    clock_t interpolation_search_end_time = clock();

    if (index != -1)
        printf("Element found at index: %d\n", index);
    else
        printf("Element not found\n");

    double bubble_sort_runtime = (double)(bubble_sort_end_time - start_time) / CLOCKS_PER_SEC;
    double interpolation_search_runtime = (double)(interpolation_search_end_time - interpolation_search_start_time) / CLOCKS_PER_SEC;
    printf("Bubble Sort Runtime: %.6f seconds\n", bubble_sort_runtime);
    printf("Interpolation Search Runtime: %.6f seconds\n", interpolation_search_runtime);

    return 0;
}
