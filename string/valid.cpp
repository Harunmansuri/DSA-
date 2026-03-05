#include<bits/stdc++.h>

using namespace std;
int main(){
     string s;
     getline(cin,s);
     int n = s.size();
     int cntstar =0;
     int hascount =0;

     for(int i=0; i<n; i++){
        if(s[i]== '*'){
            cntstar++;
        }
        else{
            hascount++;
        }
     }

     cout<<cntstar-hascount<<endl;
     return 0;




}