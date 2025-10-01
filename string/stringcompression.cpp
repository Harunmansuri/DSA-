#include <bits/stdc++.h>
using namespace std;

//leetcode 443

/*
  Function: compressString
  Purpose: Perform string compression on a given vector of characters.
  Example: 
    Input  : a a b b c c c
    Output : a 2 b 2 c 3   (length = 6)
  Logic:
    - Use two pointers: i (current position) and j (next different char).
    - Count frequency of each character.
    - Write character + count (if > 1) in the same vector.
    - Return new compressed length.
*/
int compressString(vector<char> &chars, int n)
{
    int i = 0;            // Pointer to traverse the input
    int writeIndex = 0;   // Position to write compressed result

    while (i < n)
    {
        int j = i + 1;

        // Move j until a different character is found
        while (j < n && chars[i] == chars[j])
        {
            j++;
        }

        // Write the current character
        chars[writeIndex] = chars[i];
        writeIndex++;

        // Count frequency of current char
        int count = j - i;

        // If frequency > 1, write the count as digits
        if (count > 1)
        {
            string cnt = to_string(count);
            for (char c : cnt)
            {
                chars[writeIndex] = c;
                writeIndex++;
            }
        }

        // Move to next distinct character
        i = j;
    }

    // Return the length of compressed string
    return writeIndex;
}

int main()
{
    int n;
    cout << "Enter size of input: ";
    cin >> n;

    vector<char> chars(n);
    cout << "Enter characters (space separated): ";
    for (int i = 0; i < n; i++)
    {
        cin >> chars[i];
    }

    int newLength = compressString(chars, n);

    cout << "Compressed string: ";
    for (int i = 0; i < newLength; i++)
    {
        cout << chars[i] << " ";
    }
    cout << endl;

    cout << "Compressed length: " << newLength << endl;

    return 0;
}
