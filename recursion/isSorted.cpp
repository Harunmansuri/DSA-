#include<bits/stdtr1c++.h>
using namespace std;

bool isSorted(int arr[], int size){
    if(size ==0 || size ==1){
        return true;
    }
    if(arr[0] > arr[1]){
        return false;
    }
    else{
       bool remaining= isSorted(arr+1,size-1);
       return remaining;
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
   bool ans= isSorted(arr,n);
   if(ans){
    cout << "arr is sorted"<<endl;
   }
   else{
    cout<<"arr is not sorted"<<endl;
   }
}