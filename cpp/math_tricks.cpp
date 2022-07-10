#include <bits/stdc++.h>

using namespace std;

// this is collection of math problem with special case
// in this case, solve using only addition
namespace MathTricks
{
    // negate a number
    int negate(int a)
    {
        int res = 0;
        int root = (a < 0) ? 1 : -1;
        while (a != 0)
        {
            res += root;
            a = a + root;
        }
        return res;
    }

    // multiplication
    int multiply(int a, int b)
    {
        int res = 0;
        int n = abs(b);
        while (n > 0)
        {
            res += a;
        }
        if (b < 0)
            return negate(res);
        return res;
    }

    // division
    int divide(int a, int b)
    {
        if (b == 0)
            return 0;
        int res = 0;
        int m = abs(a);
        int n = abs(b);
        int x = n;
        while (x <= m)
        {
            x += n;
            res++;
        }
        if ((a < 0) != (b < 0))
            return negate(res);
        return res;
    }
}

int main()
{
    cout << MathTricks::divide(4, 2) << endl;
    cout << MathTricks::divide(4, -2) << endl;
    cout << MathTricks::divide(-4, 2) << endl;
    cout << MathTricks::divide(-4, -2) << endl;
    cout << MathTricks::divide(4, 3) << endl;
    return 0;
}