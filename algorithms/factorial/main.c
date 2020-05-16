#include <stdio.h>
#include "fact.h"
#include "fact.c"

int main()
{
    int num;
    printf("Enter a number to find factorial:");
    scanf("%d", &num);
    printf("Factorial:%d\n", fact(num));
    return 0;
}