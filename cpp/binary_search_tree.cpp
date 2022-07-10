#include <bits/stdc++.h>

using namespace std;

struct Node
{
    Node(int v)
    {
        data = v;
    }
    int data;
    Node* left = nullptr;
    Node* right = nullptr;
};

void inorderTraversal(Node* root)
{
    if (root)
    {
        inorderTraversal(root->left);
        cout << root->data << endl;
        inorderTraversal(root->right);
    }
}

void postorderTraversal(Node* root)
{
    if (root)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << endl;
    }
}

void preorderTraversal(Node* root)
{
    if (root)
    {
        cout << root->data << endl;
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

int heightTree(Node* root)
{
    if (root)
    {
        int lheight = heightTree(root->left);
        int rheight = heightTree(root->right);

        if (lheight > rheight)
            return (lheight + 1);
        else
            return (rheight + 1);
    }
    return 0;
}

void printLevelorder(Node* root, int level)
{
    if (root)
    {
        if (level == 1)
            cout << root->data << endl;
        else if (level > 1)
        {
            printLevelorder(root->left, level-1);
            printLevelorder(root->right, level-1);
        }
    }
    else
        return;
}

void levelorderTraversal(Node* root)
{
    int h = heightTree(root);
    for (int i = 1; i <= h; i++)
        printLevelorder(root, i);
}

void levelorderTraversal2(Node* root) //using queue
{
    if (root)
    {
        std::queue<Node*> q;
        q.push(root);

        while(!q.empty())
        {
            Node* n = q.front();
            cout << n->data << endl;
            q.pop();

            if (n->left)
                q.push(n->left);
            if (n->right)
                q.push(n->right);
        }
    }
}

Node* search(Node* root, int n)
{
    if (root == nullptr)
        return root;

    if (root && root->data == n)
        return root;
    
    if (n < root->data)
        return search(root->left, n);
    else if (n > root->data)
        return search(root->right, n);
}

Node* minValueNode(Node* node)
{
    Node* cur = node;

    while (cur->left)
    {
        cur = cur->left;
    }
    return cur;
}

Node* deleteNode(Node* root, int n)
{
    if (root == nullptr)
        return root;

    if (n < root->data) // recursively find the node from left branch
        root->left = deleteNode(root->left, n);
    else if (n > root->data) // recursively find the node from right branch
        root->right = deleteNode(root->right, n);
    else if (n == root->data) // if the cur node is the node to delete
    {
        if (root->left == nullptr) // cur leaf/node didn't have left child
        {
            Node* temp = root->right; // return the right leaf whatever is the node, be it null or has leaf or branch
            delete root;
            return temp;
        }
        else if (root->right == nullptr)
        {
            Node* temp = root->left; // return left leaf, same explanation as above
            delete root;
            return temp;
        }

        // if there's child on left and right
        // find left most node / minimum value of inorder from right child to be the current root, replacing it
        Node* temp = minValueNode(root->right);

        // copy data to current node, bcos the left most node will be deleted (promoted to be the current node)
        root->data = temp->data;

        // delete it
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
////////////////////////

Node* buildTree(Node* node, int n)
{
    Node* newnode = new Node(n);
    if (node)
    {
        if (node->data > n)
        {
            if (node->left)
                buildTree(node->left, n);
            else
                node->left = newnode;
        }
        else
        {
            if (node->right)
                buildTree(node->right, n);
            else
                node->right = newnode;
        }        
    }
    else
    {
        node = newnode;
    }
    return node;
}

// ONLY FOR PREORDER ARRAY
Node* constructTreeUtil(int arr[], int* arrIndex, int val, int min, int max, int size)
{
    if (*arrIndex >= size)
        return nullptr;
    Node* node = nullptr;
    //printf("v: %d, min: %d, max: %d, size: %d \n", val, min, max, size);
    if (val > min && val < max)
    {
        node = new Node(val);
        *arrIndex = *arrIndex + 1;

        if (*arrIndex < size)
        {
            node->left = constructTreeUtil(arr, arrIndex, arr[*arrIndex], min, val, size);
            node->right = constructTreeUtil(arr, arrIndex, arr[*arrIndex], val, max, size);
        }
    }
    return node;
}
// ONLY FOR PREORDER ARRAY
Node* constructTree(int arr[], int size)
{
    int index = 0;
    return constructTreeUtil(arr, &index, arr[0], INT_MIN, INT_MAX, size);
}
//// end of

int main()
{
    Node* tree = nullptr;
    int arr[10] = {10, 5, 3, 9, 6, 1, 8, 70, 51, 23};
    for (int i = 0; i < 10; i++)
    {
        tree = buildTree(tree, arr[i]);
    }
    inorderTraversal(tree);
    cout << " -------- \n";
    /*postorderTraversal(tree);
    cout << " -------- \n";
    preorderTraversal(tree);
    cout << " -------- \n";

    int preorder[] = {10, 5, 1, 7, 40, 50}; // preorder array
    int size = sizeof(preorder) / sizeof(preorder[0]);
    Node* tree2 = constructTree(preorder, size);

    inorderTraversal(tree2);
    cout << " -------- \n levelorder \n";
    levelorderTraversal(tree);
    cout << " -------- \n levelorder \n";
    levelorderTraversal(tree2);
    cout << " -------- \n levelorder 2 \n";
    levelorderTraversal2(tree);
    cout << " -------- \n levelorder 2 \n";
    levelorderTraversal2(tree2);
    cout << " -------- \n";

    Node* foundNode = search(tree, 2);
    if(foundNode)
        cout << "found the node \n";
    else
        cout << "node not found \n";*/

    tree = deleteNode(tree, 51);
    inorderTraversal(tree);
    cout << " -------- \n after delete exist node \n";

    tree = deleteNode(tree, 2);
    inorderTraversal(tree);
    cout << " -------- \n after delete non exist node \n";

    return 0;
}