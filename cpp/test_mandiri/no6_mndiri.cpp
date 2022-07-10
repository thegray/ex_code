#include <bits/stdc++.h>

using namespace std;

// array dir: up, down, left, right
int dirRow[] = {-1, 1, 0, 0};
int dirCol[] = {0, 0, -1, 1};

bool isOK(vector<string> themap, int r, int c, int N, int M, bool **visited)
{
    return ((r >= 0) && (r < N) && (c >= 0) && (c < M) 
            && (themap[r][c] != '#') && (!visited[r][c]));
}

void DFSCust(vector<string> themap, int i, int j, int N, int M, 
    bool **visited, vector<char> &curAdj) // traverse and add to list adjacency
{
    visited[i][j] = true;
    curAdj.push_back(themap[i][j]);

    for (int d = 0; d < 4; d++)
    {
        if (isOK(themap, i + dirRow[d], j + dirCol[d], N, M, visited))
        {
            DFSCust(themap, i + dirRow[d], j + dirCol[d], 
                N, M, visited, curAdj);
        }
    }
}

string findRegion(int N, int M, vector<string> themap)
{
    string res = "\n";
    vector<vector<char>> adjList;

    bool **visited;
    visited = new bool*[N];
    for (int x = 0; x < N; x++)
    {
        visited[x] = new bool[M];
        for (int y = 0; y < M; y++)
            visited[x][y] = false;
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char cur = themap[i][j];
            if ((cur != '#') && !visited[i][j])
            {
                vector<char> curAdj;
                DFSCust(themap, i, j, N, M, visited, curAdj);
                adjList.push_back(curAdj);
            }
        }
    }

    vector<int> freq(26, 0);
    int contested = 0;
    // CHECK PER LIST, WHO OWN IT
    for (vector<char> v : adjList)
    {
        char c1 = 0;
        for (char c : v)
        {
            if (c == '.')
                continue;
            else
            {
                if (c1 == 0)
                    c1 = c;
                else if (c1 != c)
                {
                    contested++;
                    c1 = 0;
                    break;
                }
            }
        }
        if (c1 != 0)
            freq[c1 - 'a'] += 1;
    }

    for (int a = 0; a < 26; a++)
    {
        char buff[50];
        if (freq[a] > 0)
        {
            char fin = 'a' + a;
            //buff << fin << " " << freq[a] << "\n";
            sprintf(buff, "%c %d\n", fin, freq[a]);
            res += string(buff);
        }
    }
    //cout << "contested " << contested << endl;
    char buf2[50];
    sprintf(buf2, "contested %d", contested);
    res += string(buf2);
    
    // array visited deallocation
    for (int x = 0; x < N; x++)
        delete [] visited[x];
    delete [] visited;
    
    return res;
}

int main()
{
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
    getline(infile, inpt);
    int cases = stoi(inpt);
    for (int c = 1; c <= cases; c++)
    {
        getline(infile, inpt);
        int N = stoi(inpt);
        getline(infile, inpt);
        int M = stoi(inpt);
        vector<string> gridstr;
        for (int r = 0; r < N; r++)
        {
            getline(infile, inpt);
            gridstr.push_back(inpt);
        }
        string results = findRegion(N, M, gridstr);
        cout << "Case " << c << ":" << results << endl;
        outfile << "Case " << c << ":" << results << endl;
    }

    infile.close();
    outfile.close();

    return 0;
}