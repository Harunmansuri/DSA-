#include <bits/stdc++.h>
using namespace std;

vector<int> twosum(vector<int>& arr, int target, int n) {
    unordered_map<int, int> mp; 
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int complement = target - num;
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i}; // return indices of the pair
        }
        mp[num] = i; 
    }
    return {}; // no pair found
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;

    vector<int> ans = twosum(arr, target, n);
    if (!ans.empty()) {
        cout << ans[0] << " " << ans[1] << endl; 
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}
