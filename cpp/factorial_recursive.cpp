#include <bits/stdc++.h>

using namespace std;

int factorial(int x)
{
    int res = 0;
    if (x == 1)
        return 1;

    return x * factorial(x-1);
}

int factorial_tail(int x, int res = 1)
{
    if (x == 1)
        return res;
    return factorial_tail(x-1, res * x);
}

int main()
{
    int num = 5;
    cout << "factorial biasa: " << factorial(num) << endl;
    cout << "tail factorial : " << factorial_tail(num) << endl;

    return 0;
}