#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

/* 
https://www.hackerrank.com/challenges/ctci-ransom-note/problem

For this case, strongly recommended using UNORDERED_MAP
bcos data NEED NOT to be ordered or sorted
and, need to keep count of some data and single element access

reference:
https://www.geeksforgeeks.org/unordered_map-in-stl-and-its-applications/
*/

bool ransom_note(vector<string> magz, vector<string> ransom)
{
    unordered_map<string, int> umap;
    for (string key : magz)
    {
        if (umap.find(key) == umap.end())
            umap.insert(make_pair(key, 1));
        else
            umap[key]++;
    }
    for (string key2 : ransom)
    {
        if (umap.find(key2) == umap.end())
            return false;
        else
        {
            //umap[key2]--;
            //cout << "cur: key " << key2 << " val: " << umap[key2] << endl;
            if (--umap[key2] < 0)
            {
                cout << "cur: key " << key2 << " val: " << umap[key2] << endl;
                return false;
            }
        }
    }

    return true;
}

int main()
{
    /*int m;
    int n;
    cin >> m >> n;
    vector<string> magazine(m);
    for(int magazine_i = 0;magazine_i < m;magazine_i++){
       cin >> magazine[magazine_i];
    }
    vector<string> ransom(n);
    for(int ransom_i = 0;ransom_i < n;ransom_i++){
       cin >> ransom[ransom_i];
    }*/
    vector<string> magazine = {"two", "times", "three", "is", "not", "four"};
    vector<string> ransom = {"two", "times", "two", "is", "four"};
    if(ransom_note(magazine, ransom))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}