#include <bits/stdc++.h>

using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    //adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int vertices)
{
    for (int v = 0; v < vertices; v++)
    {
        cout << "\n Adjacency list of vertex "
            << v << "\n head ";
        for (auto x : adj[v])
            cout << "-> " << x;
        cout << endl;
    }
}

void DFSUtil(int start, vector<int> adj[], bool visited[])
{
    visited[start] = true;
    cout << start << " ";

    vector<int>::iterator i;
    for (i = adj[start].begin(); i != adj[start].end(); i++)
    {
        if (!visited[*i])
            DFSUtil(*i, adj, visited);
    }
}

void DFS(int start, vector<int> adj[])
{
    bool *visited = new bool[start];
    for (int i = 0; i < start; i++)
        visited[i] = false;

    for (int i = 0; i < start; i++)
        if (!visited[i])
            DFSUtil(i, adj, visited);
}

int main()
{
    int vertices = 5;
    vector<int> adj[vertices];
    int M[][5]= {  
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    int vert2 = 4;
    vector<int> adj2[vert2];
    int M2[][4]= {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {1, 0, 0, 1},
        {0, 0, 0, 1}
    };

    for (int i = 0; i < vertices; i++)
    {
        for (int j = i; j < vertices; j++)
        {
            if (M[i][j])
                addEdge(adj, i, j);
        }
    }

    for (int i2 = 0; i2 < vert2; i2++)
    {
        for (int j2 = 0; j2 < vert2; j2++)
        {
            if (M2[i2][j2])
                addEdge(adj2, i2, j2);
        }
    }

    //printGraph(adj2, vert2);

    cout << "input 0 ~ 3 :\n";
    int input;
    cin >> input;
    DFS(input, adj2);
    
    return 0;
}