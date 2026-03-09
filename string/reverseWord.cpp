#include <bits/stdc++.h>
using namespace std;

/*string reverseWord(string s)
{
    reverse(s.begin(), s.end());

    string word = "";
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        while (i < s.size() && s[i] != ' ')
        {
            word += s[i];
            i++;
        }

        reverse(word.begin(), word.end());

        if (word.length() > 0)
        {
            if (ans.length() > 0)
                ans += " ";

            ans += word;
        }

        word = "";
    }

    return ans;
}
    #include<bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    // STEP 1: Reverse the whole string
    // Example: "the sky is blue" -> "eulb si yks eht"
    reverse(s.begin(), s.end());

    int start = 0;   // Yeh current word ka starting index store karega

    // STEP 2: Puri string traverse karenge
    // i <= s.size() isliye use kiya hai taaki last word bhi process ho jaye
    for(int i = 0; i <= s.size(); i++)
    {
        // Agar space mil gaya ya string khatam ho gayi
        // Matlab ek word complete ho gaya
        if(i == s.size() || s[i] == ' ')
        {
            // Ab us word ko reverse karenge
            // start = word ka starting index
            // i = word ka ending index
            reverse(s.begin() + start, s.begin() + i);

            // Next word ka start index update karenge
            start = i + 1;
        }
    }

    // Final reversed word order string return karenge
    return s;
}

int main()
{
    string s;

    // TCS style input (space wali string lene ke liye getline use kiya)
    getline(cin, s);

    // Function call karke result print karenge
    cout << reverseWords(s);

    return 0;
}
    */
#include<bits/stdc++.h>
using namespace std;

string reverseWord(string s)
{
    stack<string> st;   // stack to store words
    string word = "";   // temporary word

    // traverse string
    for(char c : s)
    {
        // if space found -> word complete
        if(c == ' ')
        {
            if(word != "")
            {
                st.push(word);  // push word into stack
                word = "";      // reset word
            }
        }
        else
        {
            word += c;          // build word
        }
    }

    // push last word
    if(word != "")
        st.push(word);

    string ans = "";

    // pop stack to reverse words
    while(!st.empty())
    {
        ans += st.top();
        st.pop();

        if(!st.empty())
            ans += " ";
    }

    return ans;
}

int main()
{
    string s;

    // TCS style input
    getline(cin, s);

    cout << reverseWord(s);

    return 0;
}