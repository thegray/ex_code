#include <bits/stdc++.h>

using namespace std;

int sums(int num)
{
    int res = 0;
    while (num > 0)
    {
        int bil = num;
        int temp = 0;
        while (bil >= 10)
        {
            bil -= 10;
            temp++;
        }
        num = temp;
        res += bil;
    }
    return res;
}

int main()
{
    int x = 0;
    cin >> x;
    cout << sums(x) << endl;
    return 0;
}