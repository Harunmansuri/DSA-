#include <bits/stdc++.h>
using namespace std;

int secondlargest(vector<int> &arr)
{
    int n = arr.size();
    if (n < 2) return -1; // Not enough elements

    int largest = INT_MIN;
    int secondlargest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondlargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secondlargest && arr[i] < largest)
        {
            secondlargest = arr[i];
        }
    }

    if (secondlargest == INT_MIN)
        return -1; // all elements equal or no second largest

    return secondlargest;
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

    int second = secondlargest(arr);

    if (second != -1)
    {
        cout << "Second largest element is " << second << endl;
    }
    else
    {
        cout << "No second largest element exists." << endl;
    }

    return 0;
}
