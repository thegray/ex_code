#include <bits/stdc++.h>

using namespace std;

void findPair(int arr1[], int arr2[], int arr1len, int arr2len, int x)
{
    unordered_set<int> uset;
    for (int i = 0; i < arr1len; i++)
    {
        uset.insert(arr1[i]);
    }
    for (int j = 0; j < arr2len; j++)
    {
        int temp = x - arr2[j];
        if (uset.find(temp) != uset.end())
            printf("pair : %d %d \n", temp, arr2[j]);
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 7, 5, 4};
    int arr1len = sizeof(arr1)/sizeof(int);
    int arr2[] = {0, 7, 4, 3, 2, 1};
    int arr2len = sizeof(arr2)/sizeof(int);
    int x = 0;
    cin >> x;
    findPair(arr1, arr2, arr1len, arr2len, x);

    return 0;
}