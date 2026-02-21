#include <bits/stdc++.h>
using namespace std;

int secondsmallest(vector<int> &arr) {
    int n = arr.size();
    if (n < 2) return -1;

    int small = INT_MAX;
    int secondsmall = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] < small) {
            secondsmall = small;
            small = arr[i];
        } 
        else if (arr[i] < secondsmall && arr[i] != small) {
            secondsmall = arr[i];
        }
    }

    if (secondsmall == INT_MAX) return -1; // All elements equal
    return secondsmall;
}
/* vector<int> minAnd2ndMin(vector<int> &arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int mini = INT_MIN;
        int semini = INT_MIN;
        mini = arr[0];
        for(int i=0;  i<n; i++){
            if(arr[i] != mini){
                semini = arr[i];
                break;
            }
        }
        if(semini == INT_MIN){
            return {-1};
        } 
        return {mini,semini};
        
        
    }*/

int main() {
    cout << "Enter the size of array: ";
    int n;
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int small = secondsmallest(arr);
    if (small != -1) {
        cout << "Second smallest element: " << small << endl;
    } else {
        cout << "No second smallest element exists." << endl;
    }

    return 0;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> minAnd2ndMin(vector<int> &arr) {
    
    int n = arr.size();
    int mini = INT_MAX;      
    int secmini = INT_MAX;
    
    // First loop to find the minimum element in the array
    for(int i = 0; i < n; i++) {
        mini = min(mini, arr[i]);
    }

    // Second loop to find the second minimum element 
    for(int i = 0; i < n; i++) {
        if(arr[i] != mini) {
            secmini = min(secmini, arr[i]);
        }
    }

    // If second minimum was not updated, it means all elements are equal
    if(secmini == INT_MAX) {
        return {-1};  
    }

    return {mini, secmini};
}

int main() {
    vector<int> arr = {12, 25, 8, 55, 10, 33, 17, 11}; 
    vector<int> res = minAnd2ndMin(arr);  

    for(auto it : res) {
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}*/