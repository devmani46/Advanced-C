    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>

    int binary_search(int arr[], int left, int right, int target) {
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

        int target;
        printf("\nEnter Target Element: ");
        scanf("%d", &target);

        clock_t binary_search_start_time = clock();

        int index = binary_search(arr, 0, size - 1, target);

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
