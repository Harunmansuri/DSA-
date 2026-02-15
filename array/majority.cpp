#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

// Function to find majority element
int findMajorityElement(vector<int> &arr)
{
    /* int n = arr.size();

     for (int i = 0; i < n; i++) {
         int count = 0;

         for (int j = 0; j < n; j++) {
             if (arr[i] == arr[j]) {
                 count++;
             }
         }

         // Check if current element appears more than n/2 times
         if (count > n / 2) {
             return arr[i];
         }
     }

     // If no majority element found
     return -1;
     */
    /* int n = arr.size();
     map<int,int> mpp;
     for(int i=0; i<n; i++){
         mpp[arr[i]]++;
     }
     for(auto it: mpp){
        if(it.second > n/2)  {
         return it.first;
        }
     }
     return -1;
     */

    int n = arr.size();
    int el;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt = cnt + 1;
            el = arr[i];
        }
        else if (arr[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    return el;
}

int main()
{
    int n;
    cin >> n;

    // Edge case: if size is 0
    if (n <= 0)
    {
        cout << "Invalid input";
        return 0;
    }

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = findMajorityElement(arr);

    if (result != -1)
        cout << "Majority Element: " << result;
    else
        cout << "No Majority Element Found";

    return 0;
}
