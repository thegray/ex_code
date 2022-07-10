// https://www.hackerrank.com/challenges/ctci-is-binary-search-tree/problem

#include <climits>

struct Node {
    int data;
    Node* left;
    Node* right;
 };

bool isBST(Node* root, int min, int max)
{
    if (root == nullptr)
        return true;
    if (root->data < min || root->data > max)
        return false;
    return isBST(root->left, min, (root->data - 1)) && 
        isBST(root->right, (root->data + 1), max);
}

bool checkBST(Node* root) 
{
    return isBST(root, INT_MIN, INT_MAX);
}