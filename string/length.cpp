#include<bits/stdc++.h>
using namespace std;

int length(char s[]){
    int count=0;
    for(int i=0;s[i]!='\0';i++){
        count++;
    }
    return count;
}
int main(){
     char s[20];
     cin>>s;

     for(int i=0;s[i]!='\0';i++){
      cout<<s[i];
      
     }
        cout<<endl;
     cout<<"length of string is: "<<length(s);
     return 0;
}