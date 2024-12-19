#include "simple.h"

unsigned int sfactorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * sfactorial(n - 1);
}

unsigned int sfibonacchi(unsigned int n)
{
    if (n <= 1)
        return n;
    return sfibonacchi(n - 1) + sfibonacchi(n - 2);
}
