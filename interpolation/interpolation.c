#include<stdio.h>

int interpolation(int arr[],int arr_size, int search)
{
    int lo =0;
    int hi = arr_size -1;

    while(lo<=hi && search>=arr[lo] && search<=arr[hi]){
        if(lo == hi){
            if(arr[lo] == search){
                return -1;
            }
        }

        int pos = lo + (((double)(hi - lo)/ (arr[hi]- arr[lo])) *(search - arr[lo]));

        if (arr[pos] == search) 
        {
            return pos;
        }else if (arr[pos] < search)
        {
            lo = pos + 1;
        }
        
        else{
            hi = pos - 1;
        }        
            
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    
    int n;
    printf("Enter the number of elements of array: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d\n",&arr[i]);
    }


    int search;
    printf("Enter the element to search: ");
    scanf("%d",&search); 


    int x = interpolation(arr,n,search);
    if(x!= -1){
        printf("Element is present at index %d",x);
    }
    else{
        printf("Element is not present at the array");

    }

    return 0;
}
