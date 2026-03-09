#include <bits/stdc++.h>
using namespace std;

bool check(string s, int i, int j)
{
    bool a = false;
    bool b = false;
    bool c = false;

    for (int k = i; k < j; k++)
    {
        if (s[k] == 'a')
            a = true;
        if (s[k] == 'b')
            b = true;
        if (s[k] == 'c')
            c = true;
    }
    return a && b && c;
}
int allthree(string s)
{
    int count = 0;
    int n = s.length();
    // brute force approach tc O(n^3)
    /* for (int i = 0; i < n; i++)
     {
         for (int j = i; j < n; j++)
         {
             if (check(s, i, j))
             {
                count++;
             }
         }
     }
     return count;

    // optimized approach hash map of size 3 tc O(n^2)
    for (int i = 0; i < n; i++)
    {
       int hash[3] = {0};
        for (int j = i; j < n; j++)
        {
            hash[s[j]-'a']=1;
            if(hash[0]+hash[1]+hash[2]==3){
                count++;
            }
        }
    }

    return count;

    */
    // optimal
    int count = 0;
    int lastseen[3] = {-1, -1, -1};
    for (int i = 0; i < n; i++)
    {

        lastseen[s[i] - 'a'] = 1;

        if (lastseen[0] != -1 && lastseen[1] != -1 && lastseen[2] != -1)
        {
            count = count + (1 + min(lastseen[0], lastseen[1], lastseen[2]));
        }
    }
    return count;
}
int main()
{
    string s;
    getline(cin, s);
    allthree(s);
}