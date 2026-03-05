#include <bits/stdc++.h>
using namespace std;

// nlogn sortin g apporiuch
int apearOne(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i += 2)
    {
        if (arr[i] != arr[i + 1])
        {
            return arr[i];
        }
    }
    return arr[n - 1];
} // o{n2}
int apearOne(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; i < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
        }
        if (cnt == 1)
        {
            return arr[i];
        }
    }
    return -1;
}
// hashing maxsizeelemnet array  o(n)
int apearOne(vector<int> &arr)
{
    int n = arr.size();
    int maxi = arr[0];

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    vector<int> hash(maxi + 1, 0);

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hash[arr[i]] == 1)
        {
            return arr[i];
        }
    }

    return -1;
}
//nlogon map approuches
int apearOne(vector<int> &arr)
{
    int n = arr.size();
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

//xor appporches o(n ) best 
int apearOne(vector<int> &arr){
    int Xor=0;
    for(int i=0; i<arr.size(); i++){
        Xor= Xor^arr[i];
    }
    return Xor;
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

    int ans = apearOne(arr);
    cout << ans;
}