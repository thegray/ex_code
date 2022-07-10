// https://www.hackerrank.com/challenges/ctci-ice-cream-parlor/problem

#include <bits/stdc++.h>

using namespace std;

void solve(vector <int> arr, int money) 
{
    auto start = std::chrono::system_clock::now(); // time stuff

    unordered_map<int, int> lines;
    int i = 0;
    for (int price : arr)
    {
        lines[i] = price;
        i++;
    }
    int id1, id2;
    unordered_map<int, int>:: iterator itr;
    for (itr = lines.begin(); itr != lines.end(); itr++)
    {
        int cur = money;
        id1 = -1;
        id2 = -1;
        if (cur < itr->second)
            continue;
        else
        {
            cur -= itr->second;
            id1 = itr->first;
            unordered_map<int, int>:: iterator itr2;
            for (itr2 = next(itr); itr2 != lines.end(); itr2++)
            {
                if (cur == itr2->second)
                {
                    id2 = itr2->first;
                    break;
                }
            }
            if (id2 > -1)
                break;
        }
    }
    if (id1 > id2)
    {
        int temp = id1;
        id1 = id2;
        id2 = temp;
    }
    cout << (id1+1) << " " << (id2+1) << endl;
    
    // time stuff
    auto end = std::chrono::system_clock::now();
    
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
 
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}

void solve2(vector <int> arr, int money) // use the value as key DAMNNNNNNNNNNN
{
    // Complete this function
    int firstpick = 0;
    int secondpick;
    unordered_map<int,int> costTofavor;
    for(int i=0;i<arr.size();i++)
    {
        secondpick = i;
        int findthis = money - arr[i];
        cout << "findthis: " << findthis << endl;
        if(costTofavor.count(findthis) )
        {
            cout << "found\n";
            firstpick = costTofavor[money-arr[i]];
            cout<< firstpick+1 <<" "<< secondpick+1 <<endl;
            return;
        }
        costTofavor[arr[i]] = i;
     }
}

int main()
{
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int money;
        cin >> money;
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        solve2(arr, money);
    }
    return 0;
}

/*
input:
2
4
5
1 4 5 3 2
4
4
2 2 4 3

output:
1 4
1 2
*/