#include <bits/stdc++.h>
using namespace std;

/* 
   Custom stoi function
   string ko integer me convert karega
*/
int myStoi(string s)
{
    int num = 0;       // final number store
    int sign = 1;      // positive assume

    int i = 0;

    // agar first character '-' hai
    if(s[0] == '-')
    {
        sign = -1;     // number negative
        i = 1;
    }

    // remaining digits ko number banana
    for(; i < s.size(); i++)
    {
        num = num * 10 + (s[i] - '0');
    }

    return num * sign;
}

int main()
{
    string s;

    // poori line input lena
    getline(cin, s);   // example: 1 2 3 4 5

    vector<int> arr;   // final numbers store

    string temp = "";  // temporary number build

    // string ke har character par loop
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        // agar digit ya minus sign hai
        if(isdigit(c) || c == '-')
        {
            temp += c;   // number build karte jao
        }
        else
        {
            // delimiter mila (space)
            if(temp != "")
            {
                arr.push_back(myStoi(temp)); // number convert
                temp = "";                   // reset
            }
        }
    }

    // last number handle
    if(temp != "")
    arr.push_back(myStoi(temp));

    // output
    for(int x : arr)
    cout << x << " ";
}
#include <bits/stdc++.h>
using namespace std;

int myStoi(string s)
{
    int num = 0;
    int sign = 1;

    int i = 0;

    if(s[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for(; i < s.size(); i++)
    {
        num = num * 10 + (s[i] - '0');
    }

    return num * sign;
}

int main()
{
    string s;

    // example input: 1,2,3,4
    getline(cin, s);

    vector<int> arr;

    string temp = "";

    for(char c : s)
    {
        // digit ya minus
        if(isdigit(c) || c == '-')
        temp += c;

        else
        {
            // comma mila
            if(temp != "")
            {
                arr.push_back(myStoi(temp));
                temp = "";
            }
        }
    }

    if(temp != "")
    arr.push_back(myStoi(temp));

    for(int x : arr)
    cout << x << " ";
}
#include <bits/stdc++.h>
using namespace std;

int myStoi(string s)
{
    int num = 0;
    int sign = 1;

    int i = 0;

    if(s[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for(; i < s.size(); i++)
    num = num * 10 + (s[i] - '0');

    return num * sign;
}

int main()
{
    string s;

    // example input: [1,2,3,4]
    getline(cin, s);

    vector<int> arr;

    string temp = "";

    for(char c : s)
    {
        // agar digit ya minus hai
        if(isdigit(c) || c == '-')
        temp += c;

        else
        {
            // bracket ya comma mila
            if(temp != "")
            {
                arr.push_back(myStoi(temp));
                temp = "";
            }
        }
    }

    if(temp != "")
    arr.push_back(myStoi(temp));

    for(int x : arr)
    cout << x << " ";
}
#include <bits/stdc++.h>
using namespace std;

int myStoi(string s)
{
    int num = 0;
    int sign = 1;

    int i = 0;

    if(s[0] == '-')
    {
        sign = -1;
        i = 1;
    }

    for(; i < s.size(); i++)
    num = num * 10 + (s[i] - '0');

    return num * sign;
}

int main()
{
    string s;

    // example input: [[1,2],[3,4]]
    getline(cin, s);

    vector<vector<int>> arr;

    vector<int> row;

    string temp = "";

    for(char c : s)
    {
        // digit ya minus
        if(isdigit(c) || c == '-')
        temp += c;

        else
        {
            if(temp != "")
            {
                row.push_back(myStoi(temp));
                temp = "";
            }

            // row complete
            if(c == ']' && !row.empty())
            {
                arr.push_back(row);
                row.clear();
            }
        }
    }

    // print matrix
    for(auto r : arr)
    {
        for(int x : r)
        cout << x << " ";

        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    // poori line input lena
    getline(cin, s);          // example input: [ss,ss]

    vector<string> arr;       // strings store karne ke liye vector

    string temp = "";         // temporary string build karne ke liye

    // string ke har character par loop
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];        // current character

        // agar alphabet hai to string build karo
        if(isalpha(c))
        {
            temp += c;        // temp me character add karo
        }
        else
        {
            /*
               agar comma ya bracket mila
               aur temp empty nahi hai
               to ek word complete ho gaya
            */
            if(temp != "")
            {
                arr.push_back(temp); // vector me add karo
                temp = "";           // temp reset
            }
        }
    }

    // agar last string bachi ho to add karo
    if(temp != "")
    {
        arr.push_back(temp);
    }

    // output print
    for(string x : arr)
    {
        cout << x << " ";
    }
}
#include <bits/stdc++.h>
using namespace std;

/*
   check karega character digit hai ya nahi
   '0' se '9' ke beech ho to digit
*/
bool myIsDigit(char c)
{
    return (c >= '0' && c <= '9');
}

/*
   check karega character alphabet hai ya nahi
   'a-z' ya 'A-Z'
*/
bool myIsAlpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

/*
   check karega character letter ya digit hai
*/
bool myIsAlnum(char c)
{
    return myIsAlpha(c) || myIsDigit(c);
}

int main()
{
    string s;

    // poori input line read karo
    getline(cin, s);          // example input: [bb1,bb2]

    vector<string> arr;       // final strings store

    string temp = "";         // temporary string

    // string ke har character par loop
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];        // current character

        // agar letter ya digit hai
        if(myIsAlnum(c))
        {
            temp += c;        // temp string build karo
        }
        else
        {
            /*
               agar comma ya bracket mila
               aur temp empty nahi hai
               matlab word complete
            */
            if(temp != "")
            {
                arr.push_back(temp); // vector me store
                temp = "";           // reset
            }
        }
    }

    // last string handle
    if(temp != "")
    {
        arr.push_back(temp);
    }

    // output print
    for(string x : arr)
    {
        cout << x << " ";
    }
}#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    // poori input line read karo
    getline(cin, s);          // example input: [bb1,bb2]

    vector<string> arr;       // final strings store karne ke liye

    string temp = "";         // temporary string banane ke liye

    // poori string ke characters par loop
    for(int i = 0; i < s.size(); i++)
    {
        char c = s[i];        // current character

        // agar letter ya digit hai
        if(isalnum(c))
        {
            temp += c;        // temp string me add karo
        }
        else
        {
            /*
               agar comma ya bracket mila
               aur temp empty nahi hai
               matlab ek word complete ho gaya
            */
            if(temp != "")
            {
                arr.push_back(temp);  // vector me store karo
                temp = "";            // temp reset karo
            }
        }
    }

    // last string handle karne ke liye
    if(temp != "")
    {
        arr.push_back(temp);
    }

    // result print karo
    for(string x : arr)
    {
        cout << x << " ";
    }
}