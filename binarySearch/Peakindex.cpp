#include <bits/stdc++.h>
using namespace std;


int findPivot(vector<int> &arr, int n)
{
    int start = 0;
    int end = n - 1;

    while (start < end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] < arr[mid + 1])
        {
            start = mid + 1;
        }
        else 
        {
            end = mid;
        }
    }
    return start;
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = findPivot(arr, n);
    cout << "The peak index is: " << ans << endl;
}