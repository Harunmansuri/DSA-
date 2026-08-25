#include<bits/stdc++.h>
using namespace std;

int nextGreater(vector<int> &arr, int k)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        // next greater element
        if(arr[mid] > k)
        {
            ans = arr[mid];   // element store
            high = mid - 1;   // smaller greater element search
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    string s;
    getline(cin, s);

    stringstream ss(s);

    vector<int> arr;
    int num;

    while(ss >> num)
    {
        arr.push_back(num);
    }

    int k;
    cin >> k;

    cout << nextGreater(arr, k);
}