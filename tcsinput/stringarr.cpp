#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    // Step 1 : input
    getline(cin, s);        // example input -> [aa,bb,cc,dd]

    // Step 2 : remove [ and ]
    s = s.substr(1, s.size() - 2);

    // Step 3 : split by comma
    stringstream ss(s);

    vector<string> arr;
    string temp;

    while(getline(ss, temp, ','))
    {
        arr.push_back(temp);
    }

    // Step 4 : print
    for(string it : arr)
    {
        cout << it << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    // Step 1 : take input
    getline(cin, s);        // example -> [1,2,3,4]

    // Step 2 : remove '[' and ']'
    s = s.substr(1, s.size() - 2);

    // Step 3 : split using comma
    stringstream ss(s);

    vector<int> arr;
    string temp;

    while(getline(ss, temp, ','))
    {
        arr.push_back(stoi(temp)); // convert string -> int
    }

    // Step 4 : print array
    for(int it : arr)
    {
        cout << it << " ";
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    // getline पूरी line पढ़ता है
    getline(cin, s);       // input : 1 2 3 4 5

    // stringstream string को stream की तरह treat करता है
    stringstream ss(s);

    vector<int> arr;       // numbers store करने के लिए vector

    int num;

    // space मिलने पर numbers अलग हो जाते हैं
    while(ss >> num)
    {
        arr.push_back(num);   // number vector में डाल दो
    }

    // output print
    for(int x : arr)
    cout << x << " ";
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    // पूरी line पढ़ना
    getline(cin, s);   // input : 1,2,3,4,5

    stringstream ss(s);

    vector<int> arr;

    string temp;   // temporary string

    // getline का तीसरा parameter delimiter है
    // यहाँ comma पर string split होगी
    while(getline(ss, temp, ','))
    {
        arr.push_back(stoi(temp));   // string -> int convert
    }

    for(int x : arr)
    cout << x << " ";
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    getline(cin, s);  // input : [1,2,3,4]

    // substr(start,length)
    // first '[' और last ']' हटाने के लिए
    s = s.substr(1, s.size()-2);

    stringstream ss(s);

    vector<int> arr;

    string temp;

    // comma के basis पर split
    while(getline(ss, temp, ','))
    {
        arr.push_back(stoi(temp));  // string to integer
    }

    for(int x : arr)
    cout << x << " ";
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    getline(cin, s);   // input : [aa,bb,cc,dd]

    // brackets remove
    s = s.substr(1, s.size()-2);

    stringstream ss(s);

    vector<string> arr;

    string temp;

    // comma से string split
    while(getline(ss, temp, ','))
    {
        arr.push_back(temp);  // direct string store
    }

    for(string x : arr)
    cout << x << " ";
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    // rows और columns
    cin >> n >> m;

    cin.ignore(); 
    // cin के बाद newline remove करने के लिए

    vector<vector<int>> mat(n, vector<int>(m));

    for(int i = 0; i < n; i++)
    {
        string s;

        // पूरी row पढ़ना
        getline(cin, s);

        stringstream ss(s);

        for(int j = 0; j < m; j++)
        {
            ss >> mat[i][j];   // row के numbers store
        }
    }

    // print matrix
    for(auto row : mat)
    {
        for(int x : row)
        cout << x << " ";

        cout << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    getline(cin, s);   // input : [[1,2],[3,4],[5,6]]

    vector<vector<int>> arr;

    vector<int> temp;

    int num = 0;

    bool reading = false;

    // पूरी string traverse करेंगे
    for(char c : s)
    {
        // अगर digit मिला
        if(isdigit(c))
        {
            num = num*10 + (c-'0'); // number बनाना
            reading = true;
        }
        else
        {
            // अगर number complete हो गया
            if(reading)
            {
                temp.push_back(num);

                num = 0;

                reading = false;
            }

            // row complete
            if(c == ']' && !temp.empty())
            {
                arr.push_back(temp);

                temp.clear();
            }
        }
    }

    // print matrix
    for(auto row : arr)
    {
        for(int x : row)
        cout << x << " ";

        cout << endl;
    }
}