#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    stack<char> st;     // stack to track parantheses
    string result = ""; // stores  final answwr

    for (char ch : s)
    {
        if (ch == '(')
        {
            if (!st.empty())
            {
                result += ch; // add only if stack is not empty
            }
            st.push(ch); // push every '(' into stack
        }
        else if (ch == ')')
        {
            st.pop(); // pop for every ')'
            if (!st.empty())
            {
                result += ch; // add only if stack is not empty
            }
        }
    }

    cout << result << endl;
    return 0;
}

/*
Input: (()())
Stack: []
Read '(' → stack empty → skip → push
Read '(' → stack not empty → add → push
Read ')' → pop → stack not empty → add
Read '(' → stack not empty → add → push
Read ')' → pop → stack not empty → add
Read ')' → pop → stack empty → skip



⏱ Complexity (Stack)

Time: O(n)
Space: O(n)
*/

/*
Input: (()())
depth = 0

'(' → depth=1 → outermost → skip
'(' → depth=2 → add '('
')' → depth=1 → add ')'
'(' → depth=2 → add '('
')' → depth=1 → add ')'
')' → depth=0 → outermost → skip
*/


int main(){
    string s;
    cin >> s;

    int depth =0;
    string result = "";
    for(char ch : s){
        if(ch == '('){
            if(depth > 0){
                result += ch;

            }
            depth++;

        }
        else{
            depth--;
            if(depth > 0){
                result += ch;
            }
        }
    }
    cout << result;
    return 0;

}