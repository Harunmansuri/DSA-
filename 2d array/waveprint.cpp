#include <bits/stdc++.h>
using namespace std;

vector<int> printwave(vector<vector<int>> arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<int> ans;

    for (int i = 0; i < m; i++)
    {
        if (i & 1)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                ans.push_back(arr[j][i]);
            }
        }

        else
        {
            for (int j = 0; j < n; j++)
            {
                ans.push_back(arr[j][i]);
            }
        }
    }
    return ans;
}

int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
              cin >> arr[i][j];
        }
    }
   vector<int> result = printwave(arr);
    for(int i=0;i<result.size();i++){
         cout<<result[i]<<" ";
    }
     return 0;
}