#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &arr, int k)
{
    int left = 0;
    int right = 0;
    int sum = 0;
    int maxlength = 0;
    int n = arr.size();

    while (right < n)
    {
        // window expand
        sum += arr[right];

        // shrink window if sum > k
        while (sum > k)
        {
            sum -= arr[left];
            left++;
        }

        // check if sum == k
        if (sum == k)
        {
            maxlength = max(maxlength, right - left + 1);
        }

        right++;   // move right pointer
    }

    return maxlength;
}

int main()
{
    string s;
    getline(cin, s);

    vector<int> arr;
    string num = "";

    // string se numbers extract karna
    for (char ch : s)
    {
        if (isdigit(ch) || ch == '-')
        {
            num += ch;
        }
        else
        {
            if (!num.empty())
            {
                arr.push_back(stoi(num));
                num = "";
            }
        }
    }

    if (!num.empty())
    {
        arr.push_back(stoi(num));
    }

    cout << "Enter target sum: ";
    int target;
    cin >> target;

    int ans = longestSubarray(arr, target);

    cout << "Longest Subarray Length = " << ans;
}