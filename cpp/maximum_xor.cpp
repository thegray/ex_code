//https://www.hackerrank.com/challenges/maximizing-xor/problem

#include <bits/stdc++.h>
using namespace std;

//get most significant bit of the xor'ed two paramaters value
//and then fill the rest of the bit with 1

// method to get maximum xor value in range [L, R]
int maxXORInRange(int L, int R)
{
    // get xor of limits
    int xored = L ^ R;
 
    //  loop to get most significant bit position of L^R
    int msbPos = 0;
    while (xored)
    {
        msbPos++;
        xored >>= 1; //shift right, divide value by 2 per shifted bit
    }
 
    // construct result by adding 1,
    // msbPos times
    int result = 0;
    int two = 1;
    while (msbPos--)
    {
        result += two;
        two <<= 1; //shift left, multiply value by 2 per shifted bit
    }
 
    return result;
}

int main(){
    int tes = 1;
    int tes2 = 1;
    for (int i = 1; i <= 4; i++)
    {
        tes <<= i;
        tes2 <<= 1;
        cout << "tes: " << tes << endl;
        cout << "tes2: " << tes2 << endl;
    }
    int tes4 = 1 << 4;
    cout << "tes4: " << tes4 << endl;
    return 0;
}