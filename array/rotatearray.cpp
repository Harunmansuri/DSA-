#include<bits/stdc++.h>
using namespace std;

void rotatearray(vector<int> &arr,int n,int d){

    vector<int> temp(n);
    for(int i=0;i<n;i++){
        temp[(i+d)%n] = arr[i];
    }
    arr = temp;
}
    

int main(){
    int n,d;
    cin>>n>>d;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    rotatearray(arr,n,d);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}