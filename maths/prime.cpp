#include <bits/stdc++.h>
using namespace std;

// Method 1: Brute Force (O(N))
bool isPrimeBrute(int n) {
    if (n <= 1) return false;

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cnt++;
        }
    }
    return (cnt == 2);
}

// Method 2: Optimized (O(sqrt(N)))
bool isPrimeOptimized(int n) {
    if (n <= 1) return false;

    int cnt = 2; // 1 aur n ko pehle se count kar liya

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            cnt++;
            if ((n / i) != i) {
                cnt++;
            }
        }
    }
    return (cnt == 2);
}

/*bool isPrimeOptimized(int n) {

    // 0 aur 1 prime nahi hote
    if (n <= 1)
        return false;

    // sqrt(n) tak hi divisor check karna hai
    // kyunki agar n composite hoga to
    // ek factor sqrt(n) se chhota zaroor hoga
    for (int i = 2; i * i <= n; i++) {

        // Agar koi bhi divisor mil gaya
        // to number prime nahi hai
        if (n % i == 0) {
            return false;
        }
    }

    // Agar loop ke andar koi divisor nahi mila
    // to number prime hai
    return true;
}
*/

int main() {
    int n;
    cin >> n;

    // Brute Force Result
    if (isPrimeBrute(n)) {
        cout << "Brute Force: Prime Number\n";
    } else {
        cout << "Brute Force: Not Prime Number\n";
    }

    // Optimized Result
    if (isPrimeOptimized(n)) {
        cout << "Optimized: Prime Number\n";
    } else {
        cout << "Optimized: Not Prime Number\n";
    }

    return 0;
}

