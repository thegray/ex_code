#include <bits/stdc++.h>

using namespace std;

string reverseStr(string str)
{
    string res = str;
    int len = res.length();
    for (int i = 0; i < len / 2; i++)
    {
        char temp = res[i];
        res[i] = res[len - i - 1];
        res[len - i -1] = temp;
    }

    return res;
}

int findIdx(string str, char seek)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == seek) return i;
    }
    return -1;
}

string ToCustomBaseNumber(int num, string basestr)
{
    string res;
    int len = basestr.length();
    while(num)
    {
        int mod = num % len;
        //cout << "mod : " << mod << endl;
        res.push_back(basestr[mod]);
        int div = num / len;
        //cout << "div : " << div << endl;
        num = div;
    }
    return reverseStr(res);
}

long ToRealNumber(string custom, string basestr)
{
    long res = 0;
    int len = custom.length();
    for (int i = 0; i < len; i++)
    {
        res += ( pow(basestr.length(), len - i - 1) * findIdx(basestr, custom[i]));
    }
    return res;
}

int main()
{
    int x = 12345;
    cout << "custom base number, input number: \n";
    cin >> x;
    string base = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string base2 = "01";

    cout << "base : " << base << endl;
    string custom = ToCustomBaseNumber(x, base);
    cout << custom << endl;

    cout << ToRealNumber(custom, base) << endl;

    cout << " -------------------- \n";

    cout << "base : " << base2 << endl;
    string custom2 = ToCustomBaseNumber(x, base2);
    cout << custom2 << endl;

    cout << ToRealNumber(custom2, base2) << endl;
    
    return 0;
}