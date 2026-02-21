#include<bits/stdc++.h>
using namespace std;

bool checksorted(vector<int> &arr){
    int n = arr.size();
    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            return false;
        }
    }
    return true;
}
int main(){
    cout<<"Enter the size of array: ";
    int n;
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the array elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(checksorted(arr)){
        cout<<"The array is sorted in non-decreasing order."<<endl;
    } else {
        cout<<"The array is not sorted in non-decreasing order."<<endl;
    }

    
}