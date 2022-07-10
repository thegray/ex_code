#include <bits/stdc++.h>

using namespace std;

int binary_search(int* array, int value, int low, int high) {
    int mid;
    if (high < low) {
        return -1;
    } else {
        mid = (low + high)/2;
        if (array[mid] > value) {
            return binary_search(array, value, low, mid-1);
        } else if (array[mid] < value) {
            return binary_search(array, value, mid+1, high);
        } else {
            return mid;
        }
    }
}
main() {
    ifstream infile;
    infile.open("inputs/input.in");
    if (!infile)
    {
        cout << "error opening, file not found!" << endl;
        return 0;
    }

    ofstream outfile;
    outfile.open("inputs/output.in");

    string inpt;
    int value, answer;
    int array[10000];

    for (int c = 0; c < 10000; c++)
    {
        getline(infile, inpt);
        int N = stoi(inpt);
        array[c] = N;
    }
    for (int c = 0; c < 10000; c++)
    {
        getline(infile, inpt);
        value = stoi(inpt);
        answer = binary_search(array, value, 0, 9999);
        cout << answer << endl;
        //cout << "Case " << (c+1) << ":" << answer << endl;
        //outfile << "Case " << (c+1) << ":" << answer << endl;
    }

    
    /*
    for (i=0; i<10000; i++) {
        scanf("%d", &value);
        printf("%d\n", answer);
    }
    */

   /*int ar2[] = {2,4,6,8,10,12,14,16,18,20};
   for (int i = 0; i < 10; i++)
   {
       answer = binary_search(ar2, i*4, 0, 10);
       cout << answer << endl;
   }*/

    infile.close();
    outfile.close();
}