#include <bits/stdc++.h>

//https://www.hackerrank.com/challenges/handshake/problem

using namespace std;

int main() 
{
    int cases = 0, peoples = 0;
    cin >> cases;
    for(int c = 0; c < cases; ++c){
        int sums = 0, cur = 0;
        cin >> peoples;
        for(int p = 1; p < peoples; ++p){
            cur = peoples - p;
            sums += cur;
        }
        cout << sums << endl;
    }
    return 0;
}