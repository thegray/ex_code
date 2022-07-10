#include <bits/stdc++.h>

using namespace std;

void printArray(int arr[], int n);

/////////////////// INSERTION SORT ////////////////////////
// http://www.techiedelight.com/insertion-sort-iterative-recursive/
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int curVal = arr[i]; // tampung nilai yg sedang di evaluasi
        int j = i;

        // cek mundur value skrg dgn sebelahnya
        while(j > 0 && arr[j-1] > curVal)
        {
            // klo lebih kecil
            // maka pindahkan value sebelah ke posisi skrg
            arr[j] = arr[j-1];
            j--;
        }

        // masukkan value skrg ke tempatnya
        arr[j] = curVal;
    }
}

void insertionSort_recur(int arr[], int i, int n)
{
    int value  = arr[i];
    int j = i;

    while (j > 0 && arr[j-1] > value)
    {
        arr[j] = arr[j-1];
        j--;
    }

    arr[j] = value;

    if (i + 1 <= n)
        insertionSort_recur(arr, i+1, n);
}

/////////////////// QUICK SORT ////////////////////////
// http://www.techiedelight.com/quicksort/
// util function to get index of pivot after sorted 
int Partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }

    swap(arr[pIndex], arr[end]);
    return pIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int pivot = Partition(arr, start, end);

    printArray(arr, end+1);

    quickSort(arr, start, pivot - 1);
    quickSort(arr, pivot + 1, end);
}

/////////////////// MERGE SORT ////////////////////////

// util function to merge (sort) array
void merge(int arr[], int aux[], int low, int mid, int high)
{
    int k = low, i = low, j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
            aux[k++] = arr[i++]; // if left lower that right, no change
        else
            aux[k++] = arr[j++]; // swap lower element, place to aux
    }

    while (i <= mid)
    {
        aux[k++] = arr[i++]; // copy remaining elements
    }

    for (int i = low; i <= high; i++)
    {   // copy back to original array the sorted result
        arr[i] = aux[i];
    }
}

// http://www.techiedelight.com/merge-sort/
void mergeSort_recur(int arr[], int aux[], int low, int high)
{
    if (high == low)
        return;
    
    int mid = low + ((high - low)/2);

    mergeSort_recur(arr, aux, low, mid);
    mergeSort_recur(arr, aux, mid+1, high);

    merge(arr, aux, low, mid, high);
}

// http://www.techiedelight.com/iterative-merge-sort-algorithm-bottom-up/
void mergeSort(int arr[], int aux[], int low, int high)
{
    // divide the array into blocks of size m
    // m = [1,2,4,8,16,...]
    for (int m = 1; m <= high - low; m = 2*m)
    {
        // when m = 1, i = 0, 2, 4, 6, 8, ..
        // when m = 2, i = 0, 4, 8, 12, ..
        // when m = 4, i = 0, 8, 16, ..
        for (int i = low; i < high; i += 2*m)
        {
            int from = i;
            int mid = i + m - 1;
            int to = min(i + 2*m - 1, high);

            cout << from << " " << to << endl;

           merge(arr, aux, from, mid, to);
        }
    }
}

///////////////////////////////////////////////////////

int isSorted(int arr[], int size)
{
    int prev = 0;
    for (int i = 0; i < size; i++)
    {
        if (prev > arr[i])
        {
            cout << "NOT SORTED, SORT FAIL\n";
            return 0;
        }
        prev = arr[i];
    }
    return 1;
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {3,8,5,4,1,9,2};

    int ar2[] = {9, -3, 5, 2, 6, 8, -6, 1, 3};

    int n = sizeof(arr) / sizeof(int);
    int n2 = sizeof(ar2) / sizeof(int);

    //insertionSort(arr, n);

    //quickSort(ar2, 0, n2 - 1);

    int aux[n];
    for (int i = 0; i < n; i++)
    {
        aux[i] = arr[i];
    }
    mergeSort(arr, aux, 0, n - 1);

    if (isSorted(arr, n))
        printArray(arr, n);

    return 0;
}