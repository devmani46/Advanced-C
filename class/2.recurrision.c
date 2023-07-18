#include<stdio.h>

int sum(int n){
    if(n==1) return 1;
    return sum(n-1) + n;
}

int main(int argc, char const *argv[])
{
    int sumOfN = sum(5);
    printf("%d",sumOfN);
    return 0;
}

