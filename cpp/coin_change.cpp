#include <bits/stdc++.h>

using namespace std;

long coinDP(int n, vector<int> v) // FUCKKKKK HOWWWWW
{
    vector<long> DP(n+1);
    for(int z = 0; z < n+1; z++)
    {
        DP[z] = 0;
    }
    
    DP[0] = 1;
    for (int coin : v)
    {
        for (int j = coin; j < n+1; j++)
        {
            //cout << j << endl;
            //cout << DP[j - coin] << endl;
            printf("j: %d, v: %d, j-coin: %d\n", j, DP[j - coin], j-coin);
            DP[j] += DP[j - coin];
        }
    }
    long res = DP[n];
    return res;
}

int coin(int n, vector<int> v, int b)
{
    int res = 0;
    if (n == 0)
        return 1;
    
    int len = v.size();
    for (int i = 0; i < len; i++)
    {
        if (n >= v[i] && b <= v[i])
            res += coin(n - v[i], v, v[i]);
    }

    return res;
}

int main()
{
    int n = 10;
    vector<int> v = { 2,5,3,6 };
    int hasil = coin(n, v, 0);
    cout << hasil << endl;

    long hasil2 = coinDP(n, v);
    cout << hasil2 << endl;
    return 0;
}