#include <bits/stdc++.h>

using namespace std;

int findunique(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
int main()
{
    int arr[4] = {1, 1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = findunique(arr, n);
    cout << ans;
}