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

    // Base Case
    if (x == -1)
    {
        return NULL;
    }

    // New node create
    Node *temp = new Node(x);

    // Left subtree
    cout << "Enter left child of " << x << " : ";
    temp->left = buildTree();

    // Right subtree
    cout << "Enter right child of " << x << " : ";
    temp->right = buildTree();

    return temp;
}

bool isIdentical(Node *root1, Node *root2)
{
    // CASE 1:
    // Agar dono NULL hain
    // Matlab trees yaha tak same hain
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    // CASE 2:
    // Ek NULL hai aur dusra NULL nahi hai
    // Matlab structure different hai
    if ((root1 == NULL && root2 != NULL) ||
        (root1 != NULL && root2 == NULL))
    {
        return false;
    }

    // CASE 3:
    // Data different hai
    if (root1->data != root2->data)
    {
        return false;
    }

    // Recursive call:
    // Left subtree same hona chahiye
    // AND
    // Right subtree bhi same hona chahiye
    return isIdentical(root1->left, root2->left) &&
           isIdentical(root1->right, root2->right);
}

int main()
{
    cout << "Build First Tree\n";
    Node *root1 = buildTree();

    cout << "\nBuild Second Tree\n";
    Node *root2 = buildTree();

    if (isIdentical(root1, root2))
    {
        cout << "The trees are identical." << endl;
    }
    else
    {
        cout << "The trees are not identical." << endl;
    }

    return 0;
}

// tc ON Sc O(H);