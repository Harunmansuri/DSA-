#include <bits/stdc++.h>
using namespace std;

void leftrotateone(vector<int> &arr, int n)
{
    int temp = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = temp;
}

// Right rotate array by k positions
/*void drotate(vector<int> &arr, int n, int k)
{

    k = k % n;
    // Step 1: store first k elements
    vector<int> temp;
    for (int i = 0; i < k; i++)
    {
        temp.push_back(arr[i]);
    }
    // Step 2: shift remaining elements to left
    for (int i = k; i < n; i++)
    {
        arr[i - k] = arr[i];
    }
    // Step 3: put stored elements at the end
    // for (int i = 0; i < k; i++) {
    //     arr[n - k + i] = temp[i];
    // }
    for (int i = n - k; i < n; i++)
    {
        arr[i] = temp[i - (n - k)];
    }
}*/
void reverseArr(vector<int> &arr, int l, int r) {
    while (l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

// Left rotate by k using reversal
void drotate(vector<int> &arr, int n, int k) {
    k = k % n;

    // Step 1: reverse first k elements
    reverseArr(arr, 0, k - 1);

    // Step 2: reverse remaining elements
    reverseArr(arr, k, n - 1);

    // Step 3: reverse whole array
    reverseArr(arr, 0, n - 1);
}


void printarray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    int k;
    cin >> k;

    // leftrotateone(arr, n);
    drotate(arr, n, k);
    printarray(arr, n);
}