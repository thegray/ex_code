#include <bits/stdc++.h>

using namespace std;

void generateUtilWrong(char set[], string s, int setlen, int finalstringlen)
{
    if (finalstringlen == 0)
    {
        cout << "s: " << s << endl;
        return;
    }

    for (int i = 0; i < setlen; i++)
    {
        s = s + set[i]; // this is the wrong part
        cout << "len: " << finalstringlen << " s: " << s << endl;
        generateUtilWrong(set, s, setlen, finalstringlen - 1);
    }
}

void generateWrong(char set[], int setlen, int stringlen)
{
    generateUtilWrong(set, "", setlen, stringlen);
}

void generateUtil(char set[], string s, int setlen, int stringlen)
{
    if (stringlen == 0)
    {
        cout << "s: " << s << endl;
        return;
    }

    for (int i = 0; i < setlen; i++)
    {
        string s2 = s + set[i];
        generateUtil(set, s2, setlen, stringlen - 1);
    }
}

void generate(char set[], int setlen, int stringlen)
{
    generateUtil(set, "", setlen, stringlen);
}

// ---------------------------------
// THIS PART FOR PROBLEM:
// https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/

void generateUtil2(char set[], string s, int setlen, int stringlen, int oc, int cc)
{

    if (cc == stringlen)
    {
        cout << s << endl;
        return;
    }

    if (oc > cc)
    {
        string s2 = s + set[1];
        generateUtil2(set, s2, setlen, stringlen, oc, cc + 1);
    }
    if (oc < stringlen)
    {
        string s2 = s + set[0];
        generateUtil2(set, s2, setlen, stringlen, oc + 1, cc);
    }
}

void generate2(char set[], int setlen, int stringlen)
{
    int oc = 0, cc = 0;
    generateUtil2(set, "", setlen, stringlen, oc, cc);
}

void generateUtil3(int pos, int n, int oc, int cc)
{
    static char str[256];

    if (cc == n)
    {
        cout << str << endl;
        return;
    }
    else
    {
        if (oc > cc)
        {
            str[pos] = '}';
            generateUtil3(pos + 1, n, oc, cc + 1);
        }
        if (oc < n)
        {
            str[pos] = '{';
            generateUtil3(pos + 1, n, oc + 1, cc);
        }
    }
}

void generate3(int pos, int n)
{
    generateUtil3(pos, n, 0, 0);
}

// -------------- END --------------------

int main()
{
    //imba
    int charcombi = 3;
    char set[] = {'{', '}'};
    int setlen = sizeof(set)/sizeof(char);
    cout << charcombi * 2 << endl;
    //generateWrong(set, setlen, charcombi * 2);
    //generate2(set, setlen, charcombi);
    generate3(0, charcombi);
    return 0;
}