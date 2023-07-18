# include <stdio.h>
int interPolation(int a[], int aSize, int n)
{
    int low = 0, hi = aSize - 1;
    while (low <= hi && n >= a[low] && n <= a[hi])
    {
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
    int a[] = {0, 10, 20, 30, 50, 70, 75, 82, 92, 115, 123, 141, 153, 160, 170};
    int aSize = sizeof(a) / sizeof(a[0]);
    printf("Original Array: ");
    for (int i = 0; i < aSize; i++) printf("%d ", a[i]);   
    printf("\nInput a number to search: ");
    scanf("%d", &n); 
    int index = interPolation(a, aSize, n);
    if (index != -1)
        printf("\nElement found at position: %d", index);
    else
        printf("\nElement not found..!");
    return 0;
}
