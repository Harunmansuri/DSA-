#include <bits/stdc++.h>
using namespace std;

// ---------------- BRUTE FORCE ----------------
int longestSubarrayBrute(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxlength = 0;

    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];

            if (sum == k)
            {
                maxlength = max(maxlength, j - i + 1);
            }
        }
    }

    return maxlength;
}

// ---------------- PREFIX SUM (BETTER) ----------------
int longestSubarrayPrefix(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxlength = 0;

    map<long long, int> presum;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        // case when subarray starts from index 0
        if (sum == k)
        {
            maxlength = max(maxlength, i + 1);
        }

        int rem = sum - k;

        if (presum.find(rem) != presum.end())
        {
            int length = i - presum[rem];
            maxlength = max(maxlength, length);
        }

        // store prefix sum first time only
        if (presum.find(sum) == presum.end())
        {
            presum[sum] = i;
        }
    }

    return maxlength;
}

int LongestSliding(vector<int> &arr, int k)
{
    int n = arr.size();

    int l = 0;
    int r = 0;

    int sum = 0;
    int maxlength = 0;

    while (r < n)
    {
        sum += arr[r]; // add element in window

        while (sum > k)
        {
            sum -= arr[l];
            l++;
        }

        if (sum == k)
        {
            maxlength = max(maxlength, r - l + 1);
        }

        r++;
    }

    return maxlength;
}
int main()
{
    string s;
    getline(cin, s);

    vector<int> arr;
    string num = "";

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

    int k;
    cin >> k;

    cout << "Brute Force Answer: " << longestSubarrayBrute(arr, k) << endl;
    cout << "Prefix Sum Answer: " << longestSubarrayPrefix(arr, k) << endl;
    cout << "sliding window sum asnwer " << LongestSliding(arr, k) << endl;
}