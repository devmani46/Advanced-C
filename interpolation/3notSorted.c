#include <stdio.h>
#include <stdlib.h>

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
int main(int argc, char const *argv[])
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int search;
    printf("Enter the number to search: ");
    scanf("%d", &search);

    int index = interpolationSearch(a, n, search);

    if (index != -1)
        printf("Element found at position: %d\n", index);
    else
        printf("Element not found\n");
}