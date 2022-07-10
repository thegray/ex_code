#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* next;
    int data;
};

void reverseLL(Node* node)
{
    if (node == nullptr)
        return;

    reverseLL(node->next);
    cout << node->data << " ";
}

void addNext(Node* node, int d)
{
    Node* newnode = new Node;
    newnode->data = d;
    newnode->next = nullptr;
    node->next = newnode;
}

int main()
{
    int N = 10;
    Node* head = new Node;
    head->data = 0;
    Node* node = head;
    for (int i = 1; i < N; i++)
    {
        addNext(node, i);
        node = node->next;
    }

    reverseLL(head);
    cout << endl;

    Node* print = head;
    for (int j = 0; j < N; j++)
    {
        if (print)
        {
            cout << print->data << " ";
            print = print->next;
        }
    }

    return 0;
}