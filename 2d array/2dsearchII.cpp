#include <bits/stdc++.h>
using namespace std;
// Search in a 2D matrix II
// Matrix has the properties that each row is sorted in ascending order from left to right
// and each column is sorted in ascending order from top to bottom.
bool search(vector<vector<int>> &arr, int n, int m, int target){
    int r=0, c=m-1;
    while(r<n && c>=0){
        
        if(arr[r][c]==target) return true;
        else if(arr[r][c]<target) r++;
        else c--;
    }
    return false;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
        }
    }
    int target;
    cin>>target;
    if(search(arr, n, m, target)) cout << "Found";
    else cout << "Not Found";
    return 0;
}