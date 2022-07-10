// https://www.hackerrank.com/challenges/ctci-array-left-rotation/problem

#include <bits/stdc++.h>

using namespace std;

void rotateAndPrint(vector<int> vec, int len, int shift)
{
    vector<int> newv(len);
    int newindx = 0;
    for (int i = 0; i < len; i++)
    {
        newindx = (i - shift) % len;
        printf("%d, %d, %d\n", newindx, i, shift);
        newindx = (newindx < 0) ? (len + newindx) : newindx;
        newv[newindx] = vec[i];
    }
    for (int b : newv)
    {
        cout << b << " ";
    }
}

int main()
{
    vector<int> input = {1,2,3,4,5};
    int shift = 0;
    cout << "input number shift:\n";
    cin >> shift;
    rotateAndPrint(input, 5, shift);
    return 0;
}

/*
sample input:
5 4
1 2 3 4 5

output:
5 1 2 3 4
*/