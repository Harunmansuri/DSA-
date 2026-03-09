#include <bits/stdc++.h>
using namespace std;


string outermost(string s)
{
    int balance=0;
    int start=0;
    string ans="";
    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            balance++;
        }
        else{
            balance--;
        }
        if(balance ==0){
            ans+=s.substr(start+1,i-start-1);
        }
    }
    return ans;
}
string outermost(string s)
{
    string ans="";
    stack<char> st;
    for(char ch:s){
        if(ch =='('){
            if(st.empty()){
                ans+=ch;
            }
            st.push(ch);
        }
        else{
            st.pop();
            if(st.empty()){
                ans+=ch;
            }
        }
    }
    return ans;
}
//O(n);
string outermost(string s)
{
    string ans = "";
    int depth = 0;
    for (char ch : s)
    {
        if (ch == '(')
        {
            if (depth > 0)
            {
                ans += ch;
            }
            depth++;
        }
        else
        {
            if (depth > 0)
            {
                ans += ch;
            }
            depth--;
        }
    }
    return ans;
}
int main()
{
    string s;
    getline(cin, s);
    cout << outermost(s);
}

