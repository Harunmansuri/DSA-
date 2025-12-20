#include<bits/stdc++.h>
using namespace std;


void print(int i,int n){
    //base case
    if(i>n){
        return;
    }
    //cout<<i<<endl;
    print(i+1,n);
    cout<<i<<endl;
}
int main(){
    int n;
    int i=1;
    cin>>n;
    print(i,n);
    return 0;
}