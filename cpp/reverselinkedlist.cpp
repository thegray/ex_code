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

void reverse(Node** node) {
    if (!node)
        return;

    Node* head = *node;

    Node* temp = new Node;
    temp->data = head->data;
    temp->next = nullptr;
    head = head->next;

    while(head) {
        Node* temp2 = new Node;
        temp2->data = head->data;
        temp2->next = temp;
        temp = temp2;
        head = head->next;
    }    

    *node = temp;
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

    reverse(&head);

    print(head);
    print(no2);

    return 0;
}