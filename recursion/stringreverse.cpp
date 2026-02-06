#include <bits/stdc++.h>
using namespace std;

void stringReverse(string &s, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(s[start], s[end]);
    start++;
    end--;
    stringReverse(s, start, end);
}

int main()
{
    string s;
    getline(cin, s);
    int size = s.size();
    int start = 0;
    int end = size - 1;
    stringReverse(s, start, end);
    cout << s << endl;
}