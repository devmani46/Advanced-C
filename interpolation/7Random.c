#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

// int interpolationSearch(int a[], int aSize, int n) {
//     int low = 0, hi = aSize - 1;

//     while (low <= hi && n >= a[low] && n <= a[hi]) {
//         int pos = low + ((n - a[low]) * (hi - low)) / (a[hi] - a[low]);

//         if (n > a[pos])
//             low = pos + 1;
//         else if (n < a[pos])
//             hi = pos - 1;
//         else
//             return pos;
//     }

//     return -1;
// }

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

    // Generate random elements for the array
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 100;  // Generate random numbers between 0 and 99
    }

    printf("Generated elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    // Sort the array using bubble sort
    bubbleSort(a, n);

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int search;
    printf("Enter the number to search: ");
    scanf("%d", &search);

    // int index = interpolationSearch(a, n, search);
    int index = recursiveInterpolationSearch(a, 0, n - 1, search);


    if (index != -1)
        printf("Element found at position: %d\n", index);
    else
        printf("Element not found\n");


    return 0;
}
