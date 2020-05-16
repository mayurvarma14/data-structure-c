#include "fact.h"

long fact(long n)
{
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}
long facttail(long n, long a)
{
    if (n < 0)
    {
        return 0;
    }
    else if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return a;
    }
    else
    {
        return facttail(n - 1, n * a);
    }
}