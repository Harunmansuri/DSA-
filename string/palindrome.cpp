#include<bits/stdc++.h>
using namespace std;


bool palindrome(char s[],int n){
    int start=0;
    int end=n-1;
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        else{
            start++;
            end--;
        }
    }
    return true;
}
int main(){
    char s[20];
    cin>>s;
    int n=strlen(s);
    bool ans = palindrome(s,n);
    if(ans){
        cout<<"palindrome";
    }
    else{
        cout<<"not a palindrome";
    }

    return 0;

    
}