#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

bool palindrome(Node *head)

{

    Node *temp = head;
    vector<int> ans;
    while (temp != NULL)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }

    int n = ans.size();
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        if (ans[start] != ans[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
int main()
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

   bool ans = palindrome(head);
    if (ans)
    {
         cout << "Palindrome" << endl;
    }
    else
    {
         cout << "Not Palindrome" << endl;
    }
}