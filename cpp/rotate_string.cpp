// Rotate String
// https://www.hackerrank.com/challenges/rotate-string/problem

#include <bits/stdc++.h>

using namespace std;

string rotateString(string str, int shift)
{
    string newStr = str;
    int newIdx = 0;
    int len = str.length();
    for (int i = 0; i < len; i++)
    {
        newIdx = (i - shift) % len;
        //printf("%d, %d, %d\n", i - shift, i, shift);
        newIdx = (newIdx < 0) ? (newIdx + len) : newIdx;
        newStr[newIdx] = str[i];
    
    }
    return newStr;
}

string rotate2(string str, int shift)
{
	string newStr = str;
	int newIdx = 0;
	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		newIdx = (i + shift) % len;
		newStr[i] = str[newIdx];
	}
	return newStr;
}

string rotateUsingSTLPower(string& str)
{
    char first = str[0];
    str.erase(0, 1);
    str += first;
    return str;
}

int main()
{
    string input = "abcde";
	string input2 = "12345";
    for (int i = 1; i <= input.length(); i++)
    {
        //cout << rotateString(input, i) << " ";
        //cout << rotateUsingSTLPower(input) << " ";
		cout << rotate2(input2, i) << " ";
    }
    return 0;
}

/*
input:
abc

output:
bca cab abc

input:
abcde

output:
bcdea cdeab deabc eabcd abcde
*/