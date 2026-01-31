#include <bits/stdc++.h>
using namespace std;

/*vector<int> twosum(vector<int> &arr, int target)


{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}
vector<int> twosum(vector<int> &arr, int target)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i];
        if (mpp.find(complement) != mpp.end())
        {
            return {mpp[complement], i};
        }
        mpp[arr[i]] = i;
    }
    return {-1,-1};
}
 // Variant 1: Check if two numbers sum to target using hashing
    string twoSum(vector<int>& arr, int target) {
        unordered_map<int, int> mp;  // Map to store element -> index
        int n = arr.size();
        // Iterate over all elements
        for (int i = 0; i < n; i++) {
            int complement = target - arr[i];  // Needed value to reach target sum
            // Check if complement is already in map
            if (mp.find(complement) != mp.end()) {
                return "YES";  // Pair found
            }
            // Store current element with its index for future reference
            mp[arr[i]] = i;
        }
        // No pair found
        return "NO";
}

 // Variant 1: Check if two numbers sum to target using two-pointer approach
    string twoSumExists(vector<int> arr, int target) {
        int n = arr.size();
        // Create a vector of pairs to remember original indices after sorting
        vector<pair<int, int>> numsWithIndex;
        for (int i = 0; i < n; i++) {
            numsWithIndex.push_back({arr[i], i});
        }
        // Sort based on the element values
        sort(numsWithIndex.begin(), numsWithIndex.end());

        int left = 0, right = n - 1;
        // Loop until pointers cross
        while (left < right) {
            int sum = numsWithIndex[left].first + numsWithIndex[right].first;
            if (sum == target) {
                return "YES";  // Pair found
            } else if (sum < target) {
                left++;  // Need bigger sum, move left pointer right
            } else {
                right--; // Need smaller sum, move right pointer left
            }
        }
        return "NO";  // No pair found
    }
    */
// Variant 2: Return original indices of two numbers that sum to target
vector<int> twosum(vector<int> arr, int target)
{
    int n = arr.size();
    vector<pair<int, int>> numsWithIndex;
    for (int i = 0; i < n; i++)
    {
        numsWithIndex.push_back({arr[i], i});
    }
    sort(numsWithIndex.begin(), numsWithIndex.end());

    int left = 0, right = n - 1;
    while (left < right)
    {
        int sum = numsWithIndex[left].first + numsWithIndex[right].first;
        if (sum == target)
        {
            // Return original indices
            return {numsWithIndex[left].second, numsWithIndex[right].second};
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return {-1, -1}; // No pair found
}

int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = twosum(arr, target);
    cout << ans[0] << " " << ans[1] << endl;
}