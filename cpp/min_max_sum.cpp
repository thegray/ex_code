/*
min max sum
find the min and max value that calculate from sums of 4 of the 5 int in an array
https://www.hackerrank.com/challenges/mini-max-sum/problem
this demonstrated of sort usage
*/
#include <bits/stdc++.h>

using namespace std;

void miniMaxSum(vector<int> v)
{
    sort(v.begin(), v.end());

    int sum = 0;
    for (int i : v)
    {
        sum += i;
        //printf("v : %d\n", i);
    }

    int min = sum - v[4];
    int max = sum - v[0];
    printf("min: %d, max: %d \n", min, max);
}

void miniMaxSum(int arr[], int arrSize)
{
    sort(arr, arr + arrSize);

    int sum = 0;
    for (int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
        //printf("a : %d", arr[i]);
    }

    int min = sum - arr[4];
    int max = sum - arr[0];
    printf("min: %d, max: %d \n", min, max);
}

int main()
{
    vector<int> vArr = {5,4,3,2,1};
    int arr[5] = {9,8,7,6,5};

    miniMaxSum(vArr);
    miniMaxSum(arr, 5);

    return 0;
}