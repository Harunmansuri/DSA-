#include <bits/stdc++.h>
using namespace std;


int largest(int arr[], int n) {
    sort(arr, arr + n);   // correct way to sort array
    return arr[n - 1];    // last element will be largest
}
/*
#include <bits/stdc++.h>
using namespace std;

int largest(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    return arr.back();
}*/
/*
int largest(vector<int>& arr) {
    return *max_element(arr.begin(), arr.end());
}*/

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = largest(arr, n);
    cout << ans;
}


/*
int largest(int arr[], int n) {
    int maxi = arr[0];
    
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxi) {
            maxi = arr[i];
        }
    }
    
    return maxi;
}*/