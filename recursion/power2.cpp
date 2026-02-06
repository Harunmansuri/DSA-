#include<bits/stdc++.h>
using namespace std;

double power(double number, int pow) {

    // base case
    if (pow == 0) {
        return 1;
    }

    // handle negative power
    if (pow < 0) {
        return 1.0 / power(number, -pow);
    }

    // recursive call (fast exponentiation)
    double ans = power(number, pow / 2);

    // if power is even
    if (pow % 2 == 0) {
        return ans * ans;
    }
    // if power is odd
    else {
        return number * ans * ans;
    }
}

int main() {
    double number;
    int pow;

    cin >> number >> pow;

    // edge case
    if (number == 0 && pow < 0) {
        cout << "Not Defined";
        return 0;
    }

    double result = power(number, pow);
    cout << result;

    return 0;
}
