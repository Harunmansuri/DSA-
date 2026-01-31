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
    */

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

  //  vector<int> ans = twosum(arr, target);
  //  cout << ans[0] << " " << ans[1] << endl;
  string ans = twoSum(arr,target);
  cout<<ans;
}