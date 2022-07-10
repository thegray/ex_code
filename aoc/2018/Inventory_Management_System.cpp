// problem from :
// http://adventofcode.com/2018/day/2

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream infile;
    infile.open("aoc2.txt");
    if (!infile)
    {
        cout << "error opening, file not found!" << endl;
        return 0;
    }

    int dobel = 0;
    int thrice = 0;
    string row;
    //unordered_set<char> dblSet;
    //unordered_set<char> trplSet;
    while (getline(infile, row))
    {
        unordered_map<char, int> umap;
        for (char c : row) {
            if (umap.find(c) == umap.end()) {
                umap.insert(make_pair(c, 1));
            } else {
                umap[c]++;
            }
        }

        bool dbl = false, trpl = false;
        for (auto itr = umap.begin(); itr != umap.end(); itr++) {
            //cout << itr->first << ": " << itr->second << endl;
            if (itr->second == 2)
            {
                if (!dbl)
                {
                    dobel++;
                    dbl = true;
                }
            }                
            else if (itr->second == 3)
            {
                if (!trpl)
                {
                    thrice++;
                    trpl = true;
                }
            }                
        }
        // cout << "dobel: " << dobel << endl;
        // cout << "thrice: " << thrice << endl;
        // cout << "---------------------------" << endl;
    }
    infile.close();

    cout << "dobel: " << dobel << endl;
    cout << "thrice: " << thrice << endl;
    cout << "result: " << dobel * thrice << endl;

    return 0;
}