#include <bits/stdc++.h>
using namespace std;

int finduniqueSum(int arr[], int n)
{
    unordered_map<int, int> a;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        a[arr[i]]++;
    }
    for (auto it : a)
    {
        if (it.second == 1)
        {
            sum = sum + it.first;
        }
    }
    return sum;
}

/*
Method 1: Using Map
-------------------
This method works in all cases.
We store the frequency of each element in a map.
Then, we return the element whose frequency is 1.
Time Complexity: O(n log n)   (because map insert/search is log n)
Space Complexity: O(n)        (extra map used)
*/
int findUnique(int arr[], int n)
{
    map<int, int> mp; // map to store frequency of each element

    // Step 1: Count frequency
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    // Step 2: Check which element has frequency = 1
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            return it.first; // return the unique element
        }
    }

    // If no unique element found
    return -1;
}

/*
Method 2: Using XOR
-------------------
This method works only in a special case:
=> Every element appears exactly twice,
   except one element which appears once.
Logic: x ^ x = 0, and 0 ^ y = y
So, duplicates cancel out, and we get the unique element.
Time Complexity: O(n)
Space Complexity: O(1)
*/
int finduniqueXOR(int arr[], int n)
{
    int ans = 0; // variable to store result
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i]; // XOR all elements
    }
    return ans;
}

int main()
{
    // Example input
    int arr[] = {1, 1, 2, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]); // size of arr

    // Method 1: Using map
    int ans1 = findUnique(arr, n);

    // Method 2: Using XOR
    int ans2 = finduniqueXOR(arr, n);

    // Array for sum of unique elements
    int arr2[] = {1, 1, 2, 4, 5, 2};
    int m = sizeof(arr2) / sizeof(arr2[0]); // ✅ correct size
    int uniqueSum = finduniqueSum(arr2, m);

    // Output the results
    cout << "Unique element using Map method: " << ans1 << endl;
    cout << "Unique element using XOR method: " << ans2 << endl;
    cout << "Sum of unique elements in array: " << uniqueSum << endl;

    return 0;
}
