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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int main()
{
    Node *root = buildTree();
    cout << height(root);
}