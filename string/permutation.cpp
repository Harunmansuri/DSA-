#include <bits/stdc++.h>
using namespace std;

// Function to check if two frequency arrays are equal
bool checkEqual(int a[26], int b[26])
{
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

// Function to check if s2 contains any permutation of s1
bool permutation(string s1, string s2)
{
    int n = s1.length();
    int count1[26] = {0};

    // Step 1: Frequency count of characters in s1
    for (int i = 0; i < n; i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }

    // Step 2: First window of size n in s2
    int i = 0;
    int windowSize = n;
    int count2[26] = {0};

    while (i < s2.length() && i < windowSize)
    {
        int index = s2[i] - 'a';
        count2[index]++;
        i++;
    }

    // Check first window
    if (checkEqual(count1, count2))
    {
        return true;
    }

    // Step 3: Slide the window across s2
    while (i < s2.length())
    {
        // Add new character in window
        char newChar = s2[i] -'a';
        count2[newChar]++;

        // Remove old character from window
        char oldChar = s2[i - windowSize] - 'a';
        count2[oldChar]--;

        // Compare after sliding
        if (checkEqual(count1, count2))
        {
            return true;
        }

        i++;
    }

    return false;
}

int main()
{
    string s1, s2;
    cout << "Enter first string (s1): ";
    cin >> s1;
    cout << "Enter second string (s2): ";
    cin >> s2;

    if (permutation(s1, s2))
    {
        cout << "true (Permutation exists in s2)" << endl;
    }
    else
    {
        cout << "false (No permutation found)" << endl;
    }

    return 0;
}
