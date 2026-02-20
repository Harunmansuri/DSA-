#include<bits/stdc++.h>
using namespace std;

/*vector<int> leaders(vector<int> &arr, int n){
    bool leader;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        leader = true;

        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[i]){
                leader = false;
                break;
            }
        }

        if(leader == true){
            ans.push_back(arr[i]);
        }
    }

    return ans;   // ✅ very important

    int maxi = arr[n-1];
    for(int i=n-1; i<=0; i--){
        if(arr[i]>maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
        
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> ans = leaders(arr, n);

    for(int i = 0; i < ans.size(); i++){   // ✅ use ans.size()
        cout << ans[i] << " ";
    }
}
*/

#include <bits/stdc++.h>
using namespace std;

/*
    Leaders in an array:
    An element is a leader if it is greater than or equal
    to all elements to its right side.

    Optimal Approach:
    - Traverse from right to left
    - Keep track of maximum element seen so far
    - If current element >= max, it is a leader
    - Reverse the result at the end

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

vector<int> leaders(vector<int> &arr, int n)
{
    vector<int> ans;          // To store leaders
    int maxi = INT_MIN;       // Maximum from right side

    // Traverse from right to left
    for(int i = n - 1; i >= 0; i--)
    {
        if(arr[i] >= maxi)
        {
            ans.push_back(arr[i]);  // Current element is leader
            maxi = arr[i];         // Update maximum
        }
    }

    // Reverse because we added from right to left
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> ans = leaders(arr, n);

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}
