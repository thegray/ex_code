#include <bits/stdc++.h>

using namespace std;

int fib_memo(int n, int memo[])
{
    if (memo[n] != 0)
        return memo[n];
    int result = 0;
    if (n == 1 || n == 2)
        result = 1;
    else
        result = fib_memo(n-1, memo) + fib_memo(n-2, memo);
    //cout << "n : " << n << " res : " << result << endl;
    memo[n] = result;
    return result;
}

int fib_bottom_up(int n)
{
    int botup[n] = {0};
    if (n == 1 || n == 2)
        return 1;
    botup[1] = botup[2] = 1;
    for (int i = 3; i < (n+1); i++)
    {
        botup[i] = botup[i-1] + botup[i-2];
    }
    return botup[n];
}


int main()
{
    int n = 13;
    int memo[n+1] = {0};
    cout << fib_memo(n, memo) << endl;

    cout << fib_bottom_up(n) << endl;
    return 0;
}