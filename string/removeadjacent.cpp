#include<bits/stdc++.h>
using namespace std;


/*class Solution {
public:
    string removeDuplicates(string s) {
        string result = "";
        
        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                // Agar last char same hai toh remove kar do (pop)
                result.pop_back();
            } else {
                // Otherwise push kar do
                result.push_back(c);
            }
        }
        
        return result;
    }
};
*/
string removeAdjacent(string s){

    string sb ="";
    int n = s.size();
    for(int i=0; i<n; i++){
        bool repeated = false;

        while(i+1 < n && s[i]==s[i+1]){
            repeated = true;
            i++;

        }
        if(!repeated) sb = sb + s[i];
    }

    if(n == sb.length() || sb.empty()){
        return sb;
    }

    return removeAdjacent(sb);

}
int main(){
    string s;
    cin>>s;
    cout<<removeAdjacent(s);
}