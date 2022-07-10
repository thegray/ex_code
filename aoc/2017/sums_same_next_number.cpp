// problem from :
// http://adventofcode.com/2017/day/1

#include <bits/stdc++.h>

using namespace std;

int main()
{
    string input = "";
    cout << "what's the input?\n";

    cin >> input;
    size_t len = input.length();
    //cout << len << endl;
    //cout << input[len-1] << endl;
    size_t tracker = 0;
    int result = 0;
    char nextChar;
    for (char c : input)
    {
        if (tracker == len-1)
            nextChar = input[0];
        else
            nextChar = input[tracker+1];
        //cout << nextChar << endl;
        if (c == nextChar && isdigit(c))
            result += (c - '0');
        tracker++;
    }

    cout << result;

    return 0;
}