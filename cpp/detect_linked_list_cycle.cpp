#include <unordered_map>

using namespace std;

// https://www.hackerrank.com/challenges/ctci-linked-list-cycle/problem

struct Node
{
    int data;
    Node* next;
};

bool has_cycle(Node* head)
{
    unordered_map<Node*, int> nodetracker;
    while (head)
    {
        if (nodetracker.find(head) == nodetracker.end())
            nodetracker.insert(make_pair(head, 1));
        else
            return true;
        head = head->next;
    }
    return false;
}

/*
using vector
*/

#include <vector>

bool tes(Node* head)
{
    vector<Node*> visited;
    while (head)
    {
        if (!visited.empty())
        {
            for (Node* vnode : visited)
                if (head == vnode)
                    return true;
        }
        visited.push_back(head);
        head = head->next;
    }
    return false;
}