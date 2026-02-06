#include <bits/stdc++.h>
using namespace std;

// Permutation nikalne wala function
void solve(int arr[], int n, int index, vector<vector<int>> &ans) {

    // 👉 Jab poora array fix ho jaye
    if (index == n) {

        // current array ko vector me convert
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            temp.push_back(arr[i]);
        }

        // ans me daal diya
        ans.push_back(temp);
        return;
    }

    // 👉 Har position ke liye choices
    for (int i = index; i < n; i++) {

        swap(arr[index], arr[i]);   // fix element
        solve(arr, n, index + 1, ans); // recursion
        swap(arr[index], arr[i]);   // backtrack
    }
}

int main() {

    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> ans; // FINAL ANSWER

    solve(arr, n, 0, ans);

    // print ans
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
