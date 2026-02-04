#include<bits/stdc++.h>
using namespace std;

bool linearSearch(int arr[],int n,int key){
    if(n == 0){
        return false;
    }
    if(arr[0] == key){
        return true;
    }
    bool remaining = linearSearch(arr+1,n-1,key);
    return remaining;
}
int main(){
    int n;
    cin>>n;
    int key;
    cin>>key;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     bool ans =linearSearch(arr,n,key);
    if(ans){
        cout <<"found";
    }
    else{
        cout<<"notfound";
    }
    return 0;
}