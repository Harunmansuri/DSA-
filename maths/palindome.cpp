#include <bits/stdc++.h>
using namespace std;

bool palindrome(int digit) {
    if (digit < 0) { // Negative numbers can't be palindromes
        return false;
    }

    long long rev = 0;
    long long x = digit;

    while (x != 0) {
        int lastdigit = x % 10;
        rev = (rev * 10) + lastdigit;
        x = x / 10;
    }

    return (rev == digit);
}

int main() {
    int n;
    cin >> n;

    bool isPalindrome = palindrome(n);
    if (!isPalindrome) {
        cout << "Not palindrome" << endl;
    } else {
        cout << "Palindrome" << endl;
    }

    return 0;
}
