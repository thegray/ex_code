#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 5;
    int n = x * 2 - 1;
    int mid = n / 2;
    //cout << mid << endl;
    for (int i = 0; i < n; i++)
    {
        bool toggletop = false;
        bool toggle = false;
        bool togglebot = false;
        for (int j = 0; j < n; j++)
        {
            if (i < mid)
            {
                if (j >= mid && j <= mid + i)
                {
                    if ((mid + i + j) % 2 == 0)
                    {
                        if (!toggletop)
                        {
                            cout << "x";
                            toggletop = true;
                        }
                        else
                        {
                            cout << "o";
                            toggletop = false;
                        }
                    }
                    else
                        cout << " ";
                }
                else
                    cout << " ";
            }
            else if (i == mid)
            {
                if (j % 2 == 0)
                {
                    if (!toggle)
                    {
                        cout << "x";
                        toggle = true;
                    }
                    else
                    {
                        cout << "o";
                        toggle = false;
                    }
                }
                else
                    cout << " ";
            }
            else if (i > mid)
            {
                if (i - j <= mid && j <= mid)
                {
                    if ((i-j+1) % 2 == 0)
                    {
                        if (!togglebot)
                        {
                            cout << "x";
                            togglebot = true;
                        }
                        else
                        {
                            cout << "o";
                            togglebot = false;
                        }
                    }
                    else
                        cout << " ";
                }
                else
                    cout << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}