/*
digit from a number
and, revese a number
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int number = 12345;
    int revd = 0;
    while(number != 0)
    {
        int curLastDigit = number % 10;
        cout << curLastDigit << endl;
        revd = revd * 10 + curLastDigit;
        number = number / 10;
    }
    cout << revd << endl;
    
    return 0;
}