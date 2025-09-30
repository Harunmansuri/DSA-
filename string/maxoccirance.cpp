#include <bits/stdc++.h> // include all standard libraries
using namespace std;

// Function to get the character with maximum frequency
char getmax(string s)
{
    int n = s.size();          // length of string
    int arr[26] = {0};         // array to store frequency of 26 alphabets (a-z)

    // Traverse the string to count frequencies
    for (int i = 0; i < n; i++)
    {
        char ch = s[i];   // current character
        int number = 0;   // to store index for 'a' to 'z'

        // If lowercase character
        if (ch >= 'a' && ch <= 'z')
        {
            number = ch - 'a';   // map 'a'->0, 'b'->1, ..., 'z'->25
        }
        // If uppercase character
        else if (ch >= 'A' && ch <= 'Z')
        {
            number = ch - 'A';   // map 'A'->0, 'B'->1, ..., 'Z'->25
        }

        arr[number]++;  // increment frequency of that character
    }

    int maxi = -1;  // store maximum frequency
    int ans = 0;    // store index of character with max frequency

    // Traverse frequency array to find max occurring character
    for (int i = 0; i < 26; i++)
    {
        if (maxi < arr[i])   // check if current frequency is greater
        {
            ans = i;         // store index of character
            maxi = arr[i];   // update max frequency
        }
    }

    // Convert index back to character
    char finalans = 'a' + ans;  
    return finalans;  // return the most frequent character
}

int main()
{
    string s;
    cin >> s;  // input string

    char ans = getmax(s);  // call function, get most frequent character

    cout << ans;  // print answer
}
