#include <bits/stdc++.h>

using namespace std;

int dirr[] = {-1,-1,-1,0,0,1,1,1};
int dirc[] = {-1,0,1,-1,1,-1,0,1};

int findstr(vector<string> grd, int rows, int len, string tofind)
{
    int res = 0;
    // 
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < len; c++)
        {
            if (grd[r][c] == tofind[0])
            {
                for (int d = 0; d < 8; d++)
                {
                    int idxfind = 1;
                    int newdirr = r + dirr[d];
                    int newdirc = c + dirc[d];

                    while(newdirr >= 0 && newdirc >= 0 
                        && newdirr < rows && newdirc < len)
                    {
                        if (grd[newdirr][newdirc] == tofind[idxfind] 
                            && idxfind < tofind.length())
                        {
                            newdirr += dirr[d];
                            newdirc += dirc[d];
                            idxfind++;
                        }
                        else
                            break;
                    }
                    if (idxfind == tofind.length())
                        res++;
                }
            }
        }
    }
    return res;
}

int main()
{
    ifstream infile;
    infile.open("inputs/input5.in");
    if (!infile)
    {
        cout << "error opening, file not found!" << endl;
        return 0;
    }

    ofstream outfile;
    outfile.open("inputs/output5.in");

    string inpt;
    getline(infile, inpt);
    int cases = stoi(inpt);
    for (int c = 1; c <= cases; c++)
    {
        getline(infile, inpt);
        int rows = stoi(inpt);
        getline(infile, inpt);
        int len = stoi(inpt);
        vector<string> gridstr;
        for (int r = 0; r < rows; r++)
        {
            getline(infile, inpt);
            gridstr.push_back(inpt);
        }
        getline(infile, inpt);
        string tofind = inpt;
        int res = findstr(gridstr, rows, len, tofind);
        cout << "Case " << c << ": " << res << endl;
        outfile << "Case " << c << ": " << res << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}

/*
catt
ataa
tcac
cat
*/