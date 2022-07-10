#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[], int low, int size, int bil)
{
    while (low <= size)
    {
        int mid = low + (size - low) /2;        
        if (bil == arr[mid])
        {
            return mid;
        }
        else if(bil > arr[mid])
        {
            low = mid + 1;
        }
        else
            size = mid - 1;
    }
    return -1;
}

int binSearch2(int arr[], int low, int size, int bil)
{
    int high = size - 1;
    while(low <= high)
    {
        int mid = (low + high) / 2;
        if (bil == arr[mid])
        {
            return mid;
        }
        else if (bil > arr[mid])
        {
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40, 50};
    int size = sizeof(arr)/sizeof(int);
    int x = 0;
    cout << "binary search, input: \n";
    cin >> x;
    int res = binarySearch(arr, 0, size-1, x);
    int res2 = binSearch2(arr, 0, size, x);
    cout << res << endl;
    cout << res2 << endl;
    return 0;
}