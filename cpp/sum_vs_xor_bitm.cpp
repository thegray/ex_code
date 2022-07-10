// BIT MANIPULATION PROBLEM
// https://www.hackerrank.com/challenges/sum-vs-xor/problem

#include <bits/stdc++.h>

using namespace std;

long solve(long n) {
	long res = 1; //edge case, output is the same as the input, mindblown eh
	while (n > 0)
	{
		if ((n & 1) == 0)
			res = res * 2;
		n = n >> 1;
	}
	return res;
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	long n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	// egde case : n = 1099511627776

	long result = solve(n);

	fout << result << "\n";

	fout.close();

	return 0;
}
