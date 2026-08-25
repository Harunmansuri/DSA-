#include <bits/stdc++.h>
using namespace std;

// ---------------- NODE CLASS ----------------
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;   // node me value store karo
        left = NULL;  // initially left NULL
        right = NULL; // initially right NULL
    }
};

// ---------------- BUILD TREE ----------------
Node *BuildTree()
{
    int data;

    cout << "Enter the data for the node: ";
    cin >> data;

    // Agar -1 aaya to NULL node return karo
    if (data == -1)
    {
        return NULL;
    }

    // Naya node create karo
    Node *newNode = new Node(data);

    // Left subtree input
    cout << "Enter the data for the left child of "
         << data << endl;

    newNode->left = BuildTree();

    // Right subtree input
    cout << "Enter the data for the right child of "
         << data << endl;

    newNode->right = BuildTree();

    return newNode;
}

// ---------------- SPIRAL / ZIG-ZAG LEVEL ORDER ----------------
vector<int> levelOrderSpiral(Node *root)
{
    // Edge case
    if (root == NULL)
    {
        return {};
    }

    // s1 -> Right to Left traversal
    stack<Node *> s1;

    // s2 -> Left to Right traversal
    stack<Node *> s2;

    // Root ko first stack me push karo
    s1.push(root);

    // Final answer vector
    vector<int> ans;

    // Jab tak dono stack empty na ho
    while (!s1.empty() || !s2.empty())
    {

        // ---------- RIGHT TO LEFT ----------
        while (!s1.empty())
        {
            // Top node nikalo
            Node *temp = s1.top();
            s1.pop();

            // Answer me add karo
            ans.push_back(temp->data);

            /*
                IMPORTANT ORDER

                Pehle LEFT push karenge
                fir RIGHT push karenge

                Kyuki stack LIFO hota hai
                to next level me RIGHT pehle process hoga
            */

            if (temp->left)
            {
                s2.push(temp->left);
            }

            if (temp->right)
            {
                s2.push(temp->right);
            }
        }

        // ---------- LEFT TO RIGHT ----------
        while (!s2.empty())
        {
            // Top node nikalo
            Node *temp = s2.top();
            s2.pop();

            // Answer me add karo
            ans.push_back(temp->data);

            /*
                IMPORTANT ORDER

                Pehle RIGHT push karenge
                fir LEFT push karenge

                Taaki next level opposite direction me aaye
            */

            if (temp->right)
            {
                s1.push(temp->right);
            }

            if (temp->left)
            {
                s1.push(temp->left);
            }
        }
    }

    return ans;
}

// ---------------- MAIN FUNCTION ----------------
int main()
{
    // Tree build karo
    Node *root = BuildTree();

    // Spiral traversal call
    vector<int> ans = levelOrderSpiral(root);

    cout << "\nSpiral Level Order Traversal:\n";

    // Output print
    for (auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}

/*

================= TIME COMPLEXITY =================

O(N)

Kyuki har node sirf ek hi baar stack me push
aur pop ho raha hai.

N = total number of nodes

===================================================


================ SPACE COMPLEXITY =================

O(N)

Worst case me stacks me saare nodes aa sakte hain.

===================================================


================ DRY RUN EXAMPLE =================

Tree:

            1
          /   \
         2     3
        / \   / \
       4   5 6   7s


Output:

1 3 2 4 5 6 7


Traversal Direction:+


Level 1 -> Left to Right
Level 2 -> Right to Left
Level 3 -> Left to Right

===================================================

*/