#include<bits/stdc++.h>
using namespace std;

void bubbleSortRecursive(vector<int> &arr, int n){
    // base case
    if(n == 0 || n == 1){
        return;
    }

    // one pass of bubble sort
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            swap(arr[i], arr[i + 1]);
        }
    }

    // recursive call
    bubbleSortRecursive(arr, n - 1);
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);   
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    bubbleSortRecursive(arr, n);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
