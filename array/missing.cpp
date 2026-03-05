#include <bits/stdc++.h>
using namespace std;
// tc O(n)
/*int missing(vector<int>&arr){
    int n= arr.size()+1;
    int sum = n*(n+1)/2;
    int sum2=0;
    for(int i=0; i<n-1; i++){
          sum2+=arr[i];
    }
    return (sum-sum2);
}
//o(n)tc  o(1)space
int missing(vector<int> &arr)
{
    int N = arr.size() + 1;
    int xor1 = 0;
    // xor array elemet
    for (int i = 0; i < N - 1; i++)
    {
        xor1 ^= arr[i];
    }

    int xor2 = 0;
    // xor all number from 1 to n
    for (int i = 0; i <= N; i++)
    {
        xor2 ^= i;
    }

    // mising number is the xor of xor1 and xor2;
    return xor1 ^ xor2;
}

int missing(vector<int> &arr)
{
    int n = arr.size();
    vector<int> hash(n + 1, 0);
    for (int i = 0; i < n - 1; i++)
    {
        hash[arr[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
    return -1;
}*/
int missing(vector<int>& arr) {
    int n = arr.size() + 1;

    // Iterate from 1 to n and check
    // if the current number is present
    for (int i = 1; i <= n; i++) {
        bool found = false;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] == i) {
                found = true;
                break;
            }
        }

        // If the current number is not present
        if (!found)
            return i;
    }
    return -1;
}
int main()
{

    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> arr;

    int num;
    while (ss >> num)
    {
        arr.push_back(num);
    }

    int ans = missing(arr);
    cout << ans;
}