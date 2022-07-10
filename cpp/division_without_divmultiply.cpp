#include <bits/stdc++.h>

using namespace std;

int divide(int dividend, int divisor)
{
    if (divisor == 0)
        return 0;
    if (dividend == 0)
        return 0;

    int sign = ((dividend < 0) ^ (divisor < 0)) ? -1 : 1;

    dividend = abs(dividend);
    divisor = abs(divisor);

    int res = 0;
    while(dividend >= divisor)
    {
        res++;
        dividend -= divisor;
    }

    return res * sign;
}

int main()
{
    cout << divide(10,2) << endl;
    cout << divide(10,3) << endl;
    cout << divide(10,4) << endl;

    return 0;
}