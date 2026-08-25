#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

Node *buildTree()
{
    int x;

    cout << "Enter node value (-1 for NULL): ";
    cin >> x;

    if (x == -1)
    {
        return NULL;
    }

    Node *temp = new Node(x);

    cout << "Enter left child of " << x << " : ";
    temp->left = buildTree();

    cout << "Enter right child of " << x << " : ";
    temp->right = buildTree();

    return temp;
}

int countNonLeaves(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (!root->left && !root->right)
    {
        return 0;
    }
    return (1 + countNonLeaves(root->left) + countNonLeaves(root->right));
}

int main()
{
    Node *root = buildTree();

    cout << countNonLeaves(root);
}