#include <bits/stdc++.h>
using namespace std;

int longestConsequtive(vector<int> &arr, int n)
{
    int longest = 1;
    int lastsmaller = INT_MIN;
    int curCnt = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == lastsmaller)
        {
            curCnt = curCnt + 1;
            lastsmaller = arr[i];
        }
        else
            (arr[i] != lastsmaller)
            {
                curCnt = 1;
                lastsmaller = arr[i];
            }
        longest = max(longest, curCnt);
    }
    return longest;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = longestConsequtive(arr, n);
}
/*
#include <bits/stdc++.h>
using namespace std;

bool linearSearch(vector<int> &arr, int target)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == target)
            return true;
    }
    return false;
}

int longestConsecutive(vector<int> &arr)
{
    int n = arr.size();
    int longest = 1;

    for(int i = 0; i < n; i++)
    {
        int x = arr[i];
        int count = 1;

        // Check next consecutive numbers
        while(linearSearch(arr, x + 1))
        {
            x = x + 1;
            count++;
        }

        longest = max(longest, count);
    }

    return longest;
}

int main()
{
    vector<int> arr = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(arr);
}
*/