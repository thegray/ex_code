#include <bits/stdc++.h>

using namespace std;

// Greatest common divisor
int gcd(int m, int n)
{
    if (n == 0)
        return m;
    cout << m << " " << n << endl;
    return gcd(n, m % n);
}

int main()
{
    cout << gcd(10, 12) << endl;
    return 0;
}