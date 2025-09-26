#include <bits/stdc++.h>
using namespace std;

bool rotated_sorted_array(vector<int> &arr, int n) {
    int count = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i - 1] > arr[i]) {
            count++;
        }
    }
    if (arr[n - 1] > arr[0]) {
        count++;
    }
    return count <= 1;   // should be <=1, not <=0
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    if (rotated_sorted_array(arr, n)) {
        cout << "YES, it is a rotated sorted array\n";
    } else {
        cout << "NO, it is not a rotated sorted array\n";
    }

    return 0;
}
