#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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

int jumpSearch(int arr[], int n, int target) {
    int step = sqrt(n);
    int prev = 0;

    while (arr[step] < target && step < n) {
        prev = step;
        step += sqrt(n);
        if (step > n - 1) {
            step = n;
        }
    }

    for (int i = prev; i < step; i++) {
        if (arr[i] == target) {
            return i;
        }
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; 
    }

    printf("Generated elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t bubble_sort_start = clock();
    bubbleSort(arr, n);
    clock_t bubble_sort_end = clock();

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);


    clock_t jump_search_start = clock();
    int index = jumpSearch(arr, n, target);
    clock_t jump_search_end = clock();

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }

    double bubble_sort_runtime = (double)(bubble_sort_end - bubble_sort_start) / CLOCKS_PER_SEC;
    double jump_search_runtime = (double)(jump_search_end - jump_search_start) / CLOCKS_PER_SEC;
    printf("Bubble Sort Runtime: %.6f seconds\n", bubble_sort_runtime);
    printf("Jump Search Runtime: %.6f seconds\n", jump_search_runtime);

    return 0;
}
