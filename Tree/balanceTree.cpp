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
    cin >> x;

    // Base Case
    // -1 means NULL node
    if (x == -1)
    {
        return NULL;
    }

    // Create new node
    Node *temp = new Node(x);

    // Build left subtree
    temp->left = BuildTree();

    // Build right subtree
    temp->right = BuildTree();

    return temp;
}

// Function to calculate height
// and check balanced tree
int height(Node *root, bool &valid)
{
    // Base Case
    if (root == NULL)
    {
        return 0;
    }

    // Left subtree height
    int L = height(root->left, valid);

    // Right subtree height
    int R = height(root->right, valid);

    // Check balance condition
    // Difference should not be greater than 1
    if (abs(L - R) > 1)
    {
        valid = false;
    }

    // Return current node height
    return 1 + max(L, R);
}

// Function to check tree is balanced or not
bool isBalance(Node *root)
{
    bool valid = true;

    // Height function updates valid
    height(root, valid);

    return valid;
}

int main()
{
    /*
        Example Input:

                1
              /   \
             2     3
            / \
           4   5

        Preorder Input:
        1 2 4 -1 -1 5 -1 -1 3 -1 -1
    */

    Node *root = BuildTree();

    // Check balanced tree
    if (isBalance(root))
    {
        cout << "Tree is Balanced";
    }
    else
    {
        cout << "Tree is Not Balanced";
    }

    return 0;
}