#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};

// Function to build tree
Node *BuildTree()
{
    int x;

    cout << "Enter node value (-1 for NULL): ";
    cin >> x;

    // Base Case
    if (x == -1)
    {
        return NULL;
    }

    // New node create
    Node *temp = new Node(x);

    // Left subtree
    cout << "Enter left child of " << x << " : ";
    temp->left = BuildTree();

    // Right subtree
    cout << "Enter right child of " << x << " : ";
    temp->right = BuildTree();

    return temp;
}

// Inorder Traversal
// Left -> Root -> Right
void inorder(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);

    cout << root->data << " ";

    inorder(root->right);
}

// Mirror Function
void mirror(Node *root)
{
    // Base Case
    if (root == NULL)
    {
        return;
    }

    // Swap left and right child
    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;

    // Recursive call for left subtree
    mirror(root->left);

    // Recursive call for right subtree
    mirror(root->right);
}

int main()
{
    // Build tree
    Node *root = BuildTree();

    // Original Tree
    cout << "\nOriginal Tree (Inorder Traversal): ";
    inorder(root);

    // Convert into mirror tree
    mirror(root);

    // Mirror Tree
    cout << "\nMirror Tree (Inorder Traversal): ";
    inorder(root);

    return 0;
}