#include <bits/stdc++.h>
using namespace std;

vector<int> spiral(vector<vector<int>> &arr, int n, int m)
{
    vector<int> ans;
    int row = arr.size();
    int col = arr[0].size();
    int count = 0;
    int total = row * col;

    int starting_row = 0;
    int starting_col = 0;
    int ending_row = row - 1;
    int ending_col = col - 1;

    while (count < total)
    {
        for (int index = starting_col; index <= ending_col && count < total; index++)
        {
            ans.push_back(arr[starting_row][index]);
            count++;
        }
        starting_row++;

        for (int index = starting_row; index <= ending_row && count < total; index++)
        {
            ans.push_back(arr[index][ending_col]);
            count++;
        }
        ending_col--;

        for (int index = ending_col; index >= starting_col && count < total; index--)
        {
            ans.push_back(arr[ending_row][index]);
            count++;
        }
        ending_row--;

        for (int index = ending_row; index >= starting_row && count < total; index--)
        {
            ans.push_back(arr[index][starting_col]);
            count++;
        }
        starting_col++;
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> result = spiral(arr, n, m);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}