#include <bits/stdc++.h>
using namespace std;

// Custom function to check whether a character is a digit (0-9)
bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');   // ASCII check
}

// Custom function to convert string to integer (replacement of stoi)
int stringToInt(string s) {
    
    int num = 0;     // Final number
    int sign = 1;    // For negative numbers
    int i = 0;

    // Agar first character '-' hai
    if(s[0] == '-') {
        sign = -1;
        i = 1;   // Next index se start
    }

    // Har digit ko number me convert karo
    for(; i < s.length(); i++) {
        num = num * 10 + (s[i] - '0');
    }

    return num * sign;
}

int main() {

    string line;

    // Read full input like: [1,2,3,4,5]
    getline(cin, line);

    vector<int> arr;     // Store final integers
    string num = "";     // Temporary string to build numbers

    // Traverse each character of input string
    for(char ch : line) {

        // If character is digit or minus sign
        if(isDigit(ch) || ch == '-') {
            num += ch;   // Build number
        }
        else {
            // If delimiter found (comma or bracket)
            if(num != "") {
                arr.push_back(stringToInt(num));  // Convert manually
                num = "";   // Reset for next number
            }
        }
    }

    // Push last number (important step)
    if(num != "") {
        arr.push_back(stringToInt(num));
    }

    // Print result
    for(int x : arr) {
        cout << x << " ";
    }

    return 0;
}