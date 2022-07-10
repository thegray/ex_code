#include <bits/stdc++.h>

using namespace std;

float myPower(int x, int y)
{
    float res = 0;
    if (y == 0)
        return 1;
    else if (y < 0)
        return (1/x) * myPower(x, y+1);
    return x * myPower(x, y-1);
}

int optimizedPower(int base, int exp)
{
	if (exp == 0)
		return 1;
	
	int temp = optimizedPower(base, exp / 2);
	
	if (exp % 2 == 0)
		return temp * temp;
	else
		return temp * temp * base;
}

float myPower_tail(int x, int y, float res=1)
{
    if (y == 0)
        return res;
    else if (y < 0)
        return myPower_tail(x, y+1, res * (1/x));
    return myPower_tail(x, y-1, res * x);
}

int main()
{
    //
    int num = 3;
    int pwr = 3;

    cout << "rekursif biasa: " << myPower(num, pwr) << endl;
    cout << "tail rekursif: " << myPower_tail(num, pwr) << endl;
    return 0;
}