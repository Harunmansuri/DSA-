#include <bits/stdc++.h>
using namespace std;

// For multiple duplicate elements
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int x = abs(nums[i]);
        if (nums[x - 1] < 0) {
            ans.push_back(x);
        }
        nums[x - 1] = -nums[x - 1];
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = findDuplicates(nums);

    if (ans.empty()) {
        cout << "No duplicates found" << endl;
    } else {
        cout << "Duplicates: ";
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
