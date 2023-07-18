#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(int argc, char const *argv[])
{
    int N;
    printf("Enter input size of the problem: ");
    scanf("%d", &N);

    long currentSeconds = time(NULL);
    printf("%ld\n", currentSeconds);
    srand(currentSeconds);
   int randomNumber = (rand() %N) + 1;
//    RAND_MAX
   printf("%d\n",RAND_MAX);
   printf("%d\n", randomNumber);
    return 0;
}