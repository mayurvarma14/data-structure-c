#include <stdio.h>
#include "fact.h"
#include "fact.c"

int main()
{
    long num;
    printf("Enter a number to find factorial:");
    scanf("%ld", &num);
    printf("Factorial:%ld\n", facttail(num, 1));
    return 0;
}