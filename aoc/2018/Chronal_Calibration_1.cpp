// problem from :
// http://adventofcode.com/2018/day/1

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("aoc1_1.txt");
    if (!infile)
    {
        cout << "error opening, file not found!" << endl;
        return 0;
    }

    string row;
    vector<int> inpt = {};
    while (getline(infile, row)) {
        inpt.push_back(stoi(row));
    }
    infile.close();

    int result = 0;
    unordered_set<int> freq;
    bool found = false;
    while (!found) 
    {
        for (int x : inpt)
        {
            //cout << "res: " << result << ", row: " << x << endl;
            result += x;
            if (freq.find(result) == freq.end()) {
                freq.insert(result);
            } else {
                cout << "found: " << result << endl;
                found = true;
                break;
            }
        }
    }

    cout << "result: " << result << endl;

    return 0;
}