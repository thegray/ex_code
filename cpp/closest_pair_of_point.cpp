// https://www.geeksforgeeks.org/closest-pair-of-points-onlogn-implementation/

#include <bits/stdc++.h>

using namespace std;

struct Point 
{
    int x, y;
};

int closest(Point points[], int len)
{

}

int main()
{
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    cout << "The smallest distance is " << closest(P, n);
    return 0;
}