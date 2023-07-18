#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    int N;
    printf("Enter input size of the problem: ");
    scanf("%d", &N);
    printf("N = %d\n",N);
    int *arr = (int *)malloc(N*sizeof(int));
    long currentSeconds = time(NULL);
    // printf("%ld\n", currentSeconds);
    srand(currentSeconds);

    for (int i = 0; i < N; i++)
    {
        int randomNum = (rand() %N) + 1;
        int dup =0;
        for (int j = 0; j < i; j++)
        {
            if (randomNum == arr[j])
            {
                dup = 1;
                break;
            }
            
        }
        if (dup ==0){
            arr[i] = randomNum;
            printf("arr[%d] = %d\n",i,arr[i]);
        }
        else{
            i--;
        }
    }
    


//  RAND_MAX
    // printf("%d\n",RAND_MAX);
    // printf("%d\n", randomNumber);
    return 0;
}