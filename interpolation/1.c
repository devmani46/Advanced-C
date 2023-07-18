#include<stdio.h>
int search(int a[], int element, int size);

int search(int a[], int element, int size){
    int low, high,pos;
    low = 0;
    high = size-1;

    while(low<= high){
        pos = low + ((element - a[low])/ (a[high]-a[low]))* (high - low);

        if (a[pos] == element)
        {
            return pos;
        }

        else if (a[pos] > element)
        {
            high = pos -1;
        }

        else{
            low = pos + 1 ;
        }        
    }
    return -1;

}


int main(int argc, char const *argv[])
{
    int a[10] = {10,20,30,40,50,60,70,80,90,100};
    int element = 70;
    int index = search(a,element,50);

    if (index = -1)
    {
        printf("no element in the array");
    }
    else{
        printf("%d",index);
    }
    

    return 0;
}
