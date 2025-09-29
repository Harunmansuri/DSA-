#include <bits/stdc++.h>
using namespace std;

char tolowercase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch;
    } else if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}

bool isValid(char ch) {
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
        return true;
    }
    return false;
}

bool palindrome(string s) {
    int start = 0;
    int end = s.size() - 1;

    while (start <= end) {
        // agar character valid nahi hai to ignore karo
        if (!isValid(s[start])) {
            start++;
        } 
        else if (!isValid(s[end])) {
            end--;
        } 
        else {
            if (tolowercase(s[start]) != tolowercase(s[end])) {
                return false;
            }
            start++;
            end--;
        }
    }
    return true;
}

int main() {
    string s;
    getline(cin, s);   // pura line input ke liye

    bool ans = palindrome(s);

    if (ans) {
        cout << "palindrome";
    } else {
        cout << "not a palindrome";
    }

    return 0;
}
