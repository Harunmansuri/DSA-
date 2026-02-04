#include<bits/stdc++.h>

using namespace std;

int sum2(int arr[], int n , int sum){
    if(n==0){
        return sum;
    }
    if(n==1){
        return sum+arr[0];
    }
    int ans = sum2(arr+1,n-1,sum+arr[0]);
    return ans;

}
int main(){
    int n;
    cin>>n;
    int sum=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
     int ans =sum2(arr,n,sum);
    cout<<ans<<endl;
    return 0;
}