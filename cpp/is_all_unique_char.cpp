/*
check whether a string contain all unique char, (try without using additional data structure)
*/

#include <bits/stdc++.h>

using namespace std;

bool checkUnique(string s)
{
    //using array to keep the appeareance of the char
    bool appear[26] = { false }; //assume that only a ~ z char is used
    for (char c : s)
    {
        int idx = c - 'a';
        if (appear[idx])
            return false;
        appear[idx] = true;
    }

    return true;
}

bool hardImbaWay(string s) //use bit manipulation
{
    //the idea is, add new 1 bit to checker each new char appear (new bit derived from left shift of 1)
    //and compare the checker to current char (using &, if true then char has appeared before )
    int checker = 0;
    for (char c : s)
    {
        int val = c - 'a'; //bcos a is the lower possible char in this case
        int bitv = ( 1 << val);
        if (checker & bitv)
            return false;
        checker |= bitv;
    }
    return true;
}

int main()
{
    string tes = "asryvojgapqnpa";
    string tes2 = "abcdefgh";

    cout << checkUnique(tes2) << endl;
    cout << hardImbaWay(tes2) << endl;

    /*
    EXPERIMENT OF BIT MANIPULATION
    string s = "abcdefghijklmnopqrstuvwxyz";
    int checker = 0;
    for (char c : s)
    {
        int val = c - 'a';
        //cout << "val = " << val << endl;
        int v2 = (1 << val);
        checker |= v2;
        //cout << "v2 = " << v2 << " checker = " << checker << endl;
    }
    checker = checker - 256;
    int checkval = checker & (1 << 8);
    //cout << checkval << endl;
    */

    return 0;
}
