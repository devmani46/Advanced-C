#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right)
{
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
        }
        else {
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

void mergeSort(int arr[], int left, int right)
{
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
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

    mergeSort(arr, 0, size - 1);

    clock_t merge_sort_end_time = clock();

    printf("\nThe elements sorted using Merge Sort are:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    double merge_sort_runtime = (double)(merge_sort_end_time - start_time) / CLOCKS_PER_SEC * 1000000;
    printf("\nMerge Sort Runtime: %.6f microseconds\n", merge_sort_runtime);

    return 0;
}
