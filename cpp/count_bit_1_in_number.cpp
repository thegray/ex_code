//count bit 1 in a bitset of a number
//tes toped

#include <bits/stdc++.h>

using namespace std;

int count(int n)
{
    int comp = 1;
    int res = 0;
    while (comp < n)
    {
        if ((comp & n) == comp)
            res++;
        comp = comp << 1;
    }
    return res;
}

int main()
{
    int x = 0;
    cout << "count bit 1, input number: \n";
    cin >> x;
    cout << count(x);

    return 0;
}