#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node* next;
    int data;
};

void print(Node* cur) {
    while(cur) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

void addNext(Node* node, int d)
{
    Node* newnode = new Node;
    newnode->data = d;
    newnode->next = nullptr;
    node->next = newnode;
}

Node* join(Node* n1, Node* n2) {
    Node* node = new Node;
    Node* head = node;
    node->data = n1->data;
    n1 = n1->next;

    while (n1 || n2) {
        if (n1) {
            node->next = n1;
            node = node->next;
            n1 = n1->next;
        }
        if (n2) {
            node->next = n2;
            node = node->next;
            n2 = n2->next;
        }
    }

    return head;
}

int main()
{
    int N = 5;
    Node* head = new Node;
    head->data = 1;
    Node* node = head;
    for (int i = 3; i <= 9; i += 2)
    {
        addNext(node, i);
        node = node->next;
    }

    Node* no2 = new Node;
    no2->data = 2;
    Node* no2t = no2;
    for (int i = 2; i <= N; i++) {
        addNext(no2t, i*2);
        no2t = no2t->next;
    }

    print(head);
    print(no2);

    Node* tes = join(head, no2);
    print(tes);

    return 0;
}