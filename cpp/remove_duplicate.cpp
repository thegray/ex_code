// Remove Duplicates
// https://www.hackerrank.com/challenges/remove-duplicates/problem

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input = "aabc";
    int len = input.length();
    vector<int> freq(26, 0);
    for (int i = 0; i < len; i++)
    {
        char c = input[i];
        freq[c - 'a'] += 1;
        if (freq[c - 'a'] <=  1)
        {
            cout << c;
        }
    }
    cout << "\n";
    return 0;
}

/*
input:
aabc

output:
abc

input:
ccbabacc

output:
cba
*/