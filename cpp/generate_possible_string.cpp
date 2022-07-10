#include <bits/stdc++.h>

using namespace std;

void printAllUtil(char set[], string s, int len, int k)
{
    if (k == 0)
    {
        cout << s << endl;
        return;
    }

    for (int i = 0; i < len; i++)
    {
        string s2 = s + set[i];
        printAllUtil(set, s2, len, k - 1);
    }
}

void printAll(char set[], int k)
{
    int len = 2;
    printAllUtil(set, "", len, k);
}

int main()
{
    char set[] = {'B', 'K'};
    int n = 3;
    printAll(set, n*2);
    return 0;
}