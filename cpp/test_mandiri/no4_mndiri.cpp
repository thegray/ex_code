#include <bits/stdc++.h>

using namespace std;

int findDivisiveNumber(int a, int b, int c)
{
    int res = 0;
    for (int i = a; i <= b; i++)
    {
        if (i % c == 0)
        {
            res++;
        }
    }
    return res;
}

int main()
{
    ifstream infile;
    infile.open("inputs/input.in");
    if (!infile)
    {
        cout << "error opening, file not found!" << endl;
        return 0;
    }

    ofstream outfile;
    outfile.open("inputs/output.in");

    string row;
    int checksum = 0;
    bool inCase = false;
    bool isA = false, isB = false, isC = false;
    int a = 0, b = 0, c = 0;;
    int cases = 1;
    while (getline(infile, row))
    {
        int inpt = stoi(row);
        if (!inCase)
        {
            inCase = true;
            continue;
        }
        if (!isA)
        {
            a = inpt;
            isA = true;
        }
        else if (!isB)
        {
            b = inpt;
            isB = true;
        }
        else if (!isC)
        {
            c = inpt;
            isC = true;
        }
        if (isA && isB && isC)
        {
            int r = findDivisiveNumber(a, b, c);
            //printf("Case %d: %d\n", cases, r);
            outfile << "Case " << cases << ": " << r << "\n";
            cases++;
            isA = isB = isC = false;
        }
    }

    infile.close();
    outfile.close();

    return 0;
}