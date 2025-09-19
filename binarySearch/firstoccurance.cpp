#include <bits/stdc++.h>
using namespace std;

int firstOccurance(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1; // to search for first occurance
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the key to be searched: ";
    cin >> key;

    int ans = firstOccurance(arr, n, key);
    if (ans != -1)
    {
        cout << "First occurance of " << key << " is at index: " << ans << endl;
    }
    else
    {
        cout << key << " is not present in the array" << endl;
    }
    return 0;
}
   