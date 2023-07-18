#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
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

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bubble sort
    bubbleSort(arr, n);

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int target;
    printf("Enter the target element: ");
    scanf("%d", &target);

    int index = jumpSearch(arr, n, target);

    if (index != -1) {
        printf("Element %d found at index %d.\n", target, index);
    } else {
        printf("Element %d not found in the array.\n", target);
    }
    return 0;
}
