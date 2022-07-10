#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int src, dest;
};

class Graph
{
public:
    vector<int> *adjacencyList;

    Graph(vector<Edge> const &es, int N)
    {
        adjacencyList = new vector<int>[N];

        for (int i = 0; i < es.size(); i++)
        {
            int src = es[i].src;
            int dest = es[i].dest;
            
            adjacencyList[src].push_back(dest);
            adjacencyList[dest].push_back(src);
        }
    }

    ~Graph()
    {
        delete[] adjacencyList;
    }
};

/////////////////////////////////////////////////////////////

// http://www.techiedelight.com/depth-first-search/
void DFS_recur(Graph const &graph, int curNode, vector<bool> &visited) // careful for the dereference here
{
    visited[curNode] = true;
    cout << curNode << " ";

    vector<int> curAdjacency = graph.adjacencyList[curNode];
    int curLen = curAdjacency.size();

    for (int i = 0; i < curLen; i++)
    {
        int neighborNode = curAdjacency[i];
        if (!visited[neighborNode])
            DFS_recur(graph, neighborNode, visited);
    }
}

void DFS(Graph const &graph, int curNode, vector<bool> &visited)
{
    stack<int> s;
    s.push(curNode);

    while(!s.empty())
    {
        int node = s.top();
        s.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        cout << node << " ";
  
        vector<int> curAdjacency = graph.adjacencyList[node];
        int curLen = curAdjacency.size();
        for (int ri = curLen - 1; ri >= 0; ri--)
        {
            int neighborNode = curAdjacency[ri];
            
            if (!visited[neighborNode])
            {
                s.push(neighborNode);
            }
        }
    }
}

///////////////////////////////////////////////////////////

// http://www.techiedelight.com/breadth-first-search/
void BFS(Graph const &graph, int node, vector<bool> &discovered)
{
    queue<int> q;

    discovered[node] = true;
    q.push(node);


    while(!q.empty())
    {
        node = q.front();
        q.pop();
        cout << node << " ";

        vector<int> curAdjacency = graph.adjacencyList[node];

        for (int neighborNode : curAdjacency)
        {
            if (!discovered[neighborNode])
            {
                discovered[neighborNode] = true;
                q.push(neighborNode);
            }
        }
    }
}

//////////////////////////////////////////////////

void BFS_recursif(Graph const &graph, queue<int> &q, vector<bool> &discovered)
{
    if (!q.empty())
    {
        int node = q.front();
        q.pop();
        cout << node << " ";

        vector<int> curAdjacency = graph.adjacencyList[node];
        for (int neighborNode : curAdjacency)
        {
            if (!discovered[neighborNode])
            {
                discovered[neighborNode] = true;
                q.push(neighborNode);
            }
        }
        
        BFS_recursif(graph, q, discovered);
    }
}

int main()
{
    vector<Edge> edges = {
        {1,2}, {1,7}, {1,8}, {2,3}, {2,6}, {3,4}, {3,5}, {8,9}, {8,12}, {9, 10}, {9,11}
    };
    vector<Edge> edges2 = {
        {1,2},{1,3},{1,4},{2,5},{2,6},{5,9},{5,10},{4,7},{4,8},{7,11},{7,12}
    };
    int nodesNumber = 13, nodesNumber2 = 15;

    Graph graph(edges, nodesNumber);
    Graph graph2(edges2, nodesNumber2);

    vector<bool> visited(nodesNumber, false);
    vector<bool> visited2(nodesNumber2, false);

//////////////// START TRAVERSE /////////////////////////

    for (int i = 0; i < nodesNumber; i++)
    {
        if (!visited[i])
            DFS_recur(graph, i, visited);
            //BFS(graph2, i, visited2);
    }
    cout << endl;

    vector<bool> visitedNew(nodesNumber, false);
        for (int i = 0; i < nodesNumber; i++)
    {
        if (!visitedNew[i])
            DFS(graph, i, visitedNew);
    }

    cout << endl;
    vector<bool> visitedBfs(nodesNumber, false);
    /////// BFS RECURSIVE ///////////
    queue<int> q;
    for (int j = 0; j < nodesNumber; j++)
    {
        if(!visitedBfs[j])
        {
            visitedBfs[j] = true;
            q.push(j);
            //BFS_recursif(graph, q, visitedBfs);
        }
    }
    //////////////////////////////////

    return 0;
}