// #include<stdio.h>
// // 11,22,23,8,14,28,25,15,7,10,30,9,6,17,33,19
// void mergeSort(int arr[],int start,int last){
//     if(start<last){
//         int mid = (start + last)/2;
//         mergeSort(arr,start,mid);
//         mergeSort(arr,mid+1,last);
//         merge(arr,start,mid,last);
//     }
// }

#include<stdio.h>

void merge(int sourceArray[],int start,int mid,int last){
    int lSize = mid + 1;
    int rSize = last - mid;

    int lArray [lSize];
    int rArray [rSize];

    int l=0;
    int s=0;

    while (l < lSize){
        lArray [l] = sourceArray[s];
        l++;
        s++;
    }

//s = middle +1 ;
    int r =0;
        while (r < rSize){
        rArray [r] = sourceArray[s];
        r++;
        s++;
    }

    printf("Left Array elements....... \n");
    for (int i = 0; i < lSize; i++)
    {
        printf("%d\n",lArray[i]);
    }

    printf("Left Array elements....... \n");
        for (int j = 0; j < rSize; j++)
    {
        printf("%d\n",rArray[j]);
    }
    
}

int main(int argc, char const *argv[])
{
    int arr[] = {11,23,8,14,30,9,6,17,22,28,25,15,7,10,33,19};
    int start = 0;
    int arraySize = sizeof(arr) / sizeof(int);
    int last = arraySize -1;
    int mid = (start + last) / 2;
    merge(arr,start,mid,last);
}
