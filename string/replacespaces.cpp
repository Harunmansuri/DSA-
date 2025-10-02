#include <bits/stdc++.h>
using namespace std;

// Function to replace spaces with "@40"
string replaceSpaces(string s) {
    int n = s.size();
    string temp = "";

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            // Replace space with "@40"
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        } else {
            // Otherwise, keep the character as it is
            temp.push_back(s[i]);
        }
    }

    return temp; // Return the modified string
}

int main() {
    string s;
    cout << "Enter the string: ";
    // Taking input with spaces using getline
    getline(cin, s);

    // Call the function and print the result
    cout << replaceSpaces(s);

    return 0;
}
// Function to replace spaces with "@40"