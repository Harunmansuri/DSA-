#include<bits/stdc++.h>
using namespace std;


bool isPalindrome(string s, int start, int end){
    if(start>=end){
        return true;
    }
    if(s[start]!=s[end]){
        return false;
    }
    return isPalindrome(s, start+1, end-1);
}
bool ispalindrome(string s, int i ){
    int n = s.length();
    if( i >= n/2){
        return true;
    }
    if(s[i]!=s[n-i-1]){
        return false;
    }
    return ispalindrome(s, i+1);
}

int main(){
    string s;
    cin>>s;
    int n=s.length();
    bool isPalindrome=true;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]){
            isPalindrome=false;
            break;
        }
    }
    if(isPalindrome){
        cout<<"The string is a palindrome."<<endl;
    }else{
        cout<<"The string is not a palindrome."<<endl;
    }
    return 0;
}