#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to reverse a linked list
Node *reverse(Node *head) {
    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Function to find the middle node
Node *findmiddle(Node *head) {
    Node *slow = head;
    Node *fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

// Function to check if linked list is palindrome
bool palindrome(Node *head) {
    if (head == NULL || head->next == NULL) return true;

    // Step 1: Find middle
    Node *middle = findmiddle(head);

    // Step 2: Reverse second half
    Node *secondHalf = reverse(middle->next);

    // Step 3: Compare both halves
    Node *firstHalf = head;
    Node *secondHalfCopy = secondHalf; // to restore later
    bool isPalindrome = true;

    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            isPalindrome = false;
            break;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    // Step 4: Restore the list (optional)
    middle->next = reverse(secondHalfCopy);

    return isPalindrome;

    /*
    -------------------------
    Alternate (Simpler) Method:
    Using Vector to Check Palindrome
    -------------------------

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
    */
}

int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);

    bool ans = palindrome(head);
    if (ans)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}
