#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int interpolationSearch(int a[], int aSize, int n) {
    int low = 0, hi = aSize - 1;

    while (low <= hi && n >= a[low] && n <= a[hi]) {
        int pos = low + ((n - a[low]) * (hi - low)) / (a[hi] - a[low]);

        if (n > a[pos])
            low = pos + 1;
        else if (n < a[pos])
            hi = pos - 1;
        else
            return pos;
    }

    return -1;
}

int main(int argc, char const *argv[]) {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Sort the array using merge sort
    mergeSort(a, 0, n - 1);

    printf("Sorted elements: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    int search;
    printf("Enter the number to search: ");
    scanf("%d", &search);

    int index = interpolationSearch(a, n, search);

    if (index != -1)
        printf("Element found at position: %d\n", index);
    else
        printf("Element not found\n");

    free(a);

    return 0;
}
