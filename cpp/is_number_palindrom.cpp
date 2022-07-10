//https://www.geeksforgeeks.org/check-number-palindrome-not-without-using-extra-space/
//tes toped

#include <bits/stdc++.h>

using namespace std;

bool isPalindrom(int n)
{
    int div = 1;
    while (n / div >= 10)
    {
        div *= 10;
    }

    while (n != 0)
    {
        int depan = n / div;
        int blkng = n % 10;

        if (depan != blkng)
            return false;

        n = n % div;
	cout << "1: " << n << endl;
        n = n / 10;
	cout << "2: " << n << endl;

        div = div / 100;
    }
    return true;
}

int main()
{
    int x = 0;
    cout << "check number palindrom, input number: \n";
    cin >> x;
    if (isPalindrom(x))
        cout << "yes palindrom\n";
    else
        cout << "not a palindrom\n";

    return 0;
}
