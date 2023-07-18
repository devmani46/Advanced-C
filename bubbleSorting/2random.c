#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int isDuplicate(int arr[], int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return 1;
        }
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

int main(int argc, char const *argv[]) {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));

    srand(time(NULL));
    printf("Randomly generated elements: ");

    int generatedNumbers[n];  // Track generated numbers
    int count = 0;  // Count of generated numbers

    for (int i = 0; i < n; i++) {
        int num;
        do {
            num = rand() % 100;
        } while (isDuplicate(generatedNumbers, count, num));  // Check if the number is a duplicate

        generatedNumbers[count++] = num;  // Add the generated number to the list
        arr[i] = num;
        printf("%d ", arr[i]);
    }
    printf("\n");

    clock_t start_time = clock();

    bubbleSort(arr, n);

    clock_t end_time = clock();

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    double runtime = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Runtime: %.6f seconds\n", runtime);

    free(arr);  // Free allocated memory

    return 0;
}
