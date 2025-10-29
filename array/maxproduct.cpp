#include <bits/stdc++.h>
using namespace std;

int maxProduct(vector<int> &arr)
{
    int n = arr.size();
    int maxpro = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int product = arr[i] * arr[j];
            maxpro = max(maxpro, product);
        }
    }
    return maxpro;
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

    int maxproduct = maxProduct(arr);
    cout << maxproduct;
    return 0;
}
