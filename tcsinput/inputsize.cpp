#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;
    cin >> n;          // Read size

    cin.ignore();      // Remove leftover newline

    string line;
    getline(cin, line);   // Read bracket input

    vector<int> arr;
    string num = "";

    // Traverse each character
    for(char ch : line) {

        // If digit or minus sign, build number
        if(isdigit(ch) || ch == '-') {
            num += ch;
        }
        else {
            // If comma or bracket found
            if(!num.empty()) {
                arr.push_back(stoi(num));  // Convert string to integer
                num = "";                 // Reset for next number
            }
        }
    }

    // Push last number (important)
    if(!num.empty()) {
        arr.push_back(stoi(num));
    }

    // Optional: size check
    if(arr.size() != n) {
        cout << "Size mismatch";
        return 0;
    }

    // Print array
    for(int x : arr) {
        cout << x << " ";
    }

    return 0;
}