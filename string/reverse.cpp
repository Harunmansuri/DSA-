#include <bits/stdc++.h>
using namespace std;
void reverse(char s[], int n)
{
    int start = 0;
    int end = n - 1;
    while (end > start)
    {
        swap(s[start], s[end]);
        start++;
        end--;
    }
}
int main()
{
    char s[20];
    cin >> s;
    int n = strlen(s);
    reverse(s, n);
    cout << s;
}