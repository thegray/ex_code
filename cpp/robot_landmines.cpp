/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void traverse(int xpos, int ypos, int n, int m, vector<vector<int>> grid, int *result);

int main()
{
    int row = 3;
    int col = 5;
    vector<vector<int>> grid
    {
        {1, 1, 1, 1, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
    };
    int result = 0;

    // start from top-left most cell
    traverse(0, 0, row, col, grid, &result);

    cout << "Result: " << result << "\n" << endl;

    for (int i = 0; i < row; i++)
    {
        for (int x : grid[i])
        {
            cout << x << " ";
        }
        cout << endl;
    }
}

void traverse(int xpos, int ypos, int r, int c, vector<vector<int>> grid, int *result)
{
    // check if finish cell
    if (xpos == r - 1 && ypos == c - 1)
    {
        cout << "finish!" << "\n";
        int r = *result + 1;
        *result = r;
    }
    else
    {
        // if current cell is 0, no need to move from this point
        if (grid[xpos][ypos] == 0)
            return;

        // cout << "DEBUG " << grid[xpos][ypos] << " " << xpos << "|" << ypos << "\n";
        
        // check if neigboring right cell is valid, then can move to that cell
        if (xpos + 1 < r)
        {
            traverse(xpos + 1, ypos, r, c, grid, result);
        }
        // check if neigboring bottom cell is valid, then can move to that cell
        if (ypos + 1 < c)
        {
            traverse(xpos, ypos + 1, r, c, grid, result);
        }
    }
}
