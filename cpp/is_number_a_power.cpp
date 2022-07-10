/*
Check if a number can be expressed as x^y (x raised to power y)

Given a positive integer n, find if it can be expressed as xy where y > 1 and x > 0. x and y both are integers.
https://www.geeksforgeeks.org/check-if-a-number-can-be-expressed-as-xy-x-raised-to-power-y/
*/

#include <bits/stdc++.h>

bool isPower(unsigned n)
{
    if (n == 1)
        return true;

    int akar = sqrt(n);

    for (unsigned i = 2; i <= akar; i++)
    {
        unsigned curpow = i * i;

        while (curpow <= n && curpow > 0)
        {
            if (curpow == n)
                return true;
            curpow *= i;
        }
    }
    return false;
}

int main()
{
    unsigned int n = 17;
    printf("%d \n", isPower(n));

    n = 9;
    printf("%d \n", isPower(n));

    n = 8;
    printf("%d \n", isPower(n));

    for (int i = 2; i < 100; i++)
    {
        if (isPower(i))
           printf("%d ", i);
    }

    return 0;
}
