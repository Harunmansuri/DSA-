#include <bits/stdc++.h>
using namespace std;

bool search(vector<vector<int>> &arr, int target)
{
    int row = arr.size();
    int col = arr[0].size();

    int start = 0;
    int end = row * col - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;  // ✅ Correct mid calculation
        int element = arr[mid / col][mid % col];

        if (element == target)
        {
            return true;
        }
        else if (element < target)
        {
            start = mid + 1;  // ✅ Move right
        }
        else
        {
            end = mid - 1;  // ✅ Move left
        }
    }

    return false;  // ✅ If not found
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

    int target;
    cin >> target;

   if(search(arr, target)) cout << "Found";
   else cout << "Not Found";
}
