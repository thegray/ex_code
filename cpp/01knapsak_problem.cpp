#include <bits/stdc++.h>

using namespace std;

int knapsack(int n, int c, int w[], int v[])
{
    int res = 0;
    if (n == 0 || c == 0)
        res = 0;
    else if (w[(n-1)] > c)
        res = knapsack(n-1, c, w, v);
    else
    {
        int temp1 = knapsack(n-1, c, w, v);
        int temp2 = v[(n-1)] + knapsack(n-1, c - w[(n-1)], w, v);
        res = (temp1 > temp2) ? temp1 : temp2;
    }
    return res;
}

int knapsack_dynamic(int n, int c, int memo[][10], int w[], int v[])
{
    int res = 0;
    if (n == 0 || c == 0)
        res = 0;
    else if (memo[n-1][c-1] != -1)
        return memo[n-1][c-1];
    else if (w[(n-1)] > c)
        res = knapsack_dynamic(n-1, c, memo, w, v);
    else
    {
        //cout << " n: " << n << " c: " << c << endl;
        int temp1 = knapsack_dynamic(n-1, c, memo, w, v);
        int temp2 = v[(n-1)] + knapsack_dynamic(n-1, c - w[(n-1)], memo, w, v);
        //cout << "temp1: " << temp1 << " temp2: " << temp2 << " w(n): " << w[(n-1)] << endl;
        res = (temp1 > temp2) ? temp1 : temp2;
    }

    if (n > 0 && c > 0)
    {
        memo[n-1][c-1] = res;
    }
    return res;
}

int main()
{
    int n = 5;
    int c = 10;
    int w[] = {1,2,4,2,5};
    int v[] = {5,3,5,3,2};

    cout << knapsack(n, c, w, v) << endl;

    int memo[n][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            memo[i][j] = -1;
        }
    }
    cout << knapsack_dynamic(n, c, memo, w, v) << endl;

    return 0;
}