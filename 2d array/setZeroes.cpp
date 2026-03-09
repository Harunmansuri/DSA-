#include <bits/stdc++.h>
using namespace std;
/*
void markRow(int i, int m, vector<vector<int>> &arr)
{
    for (int j = 0; j < m; j++)
    {
        if (arr[i][j] != 0)
            arr[i][j] = -1;
    }
}

void markCol(int j, int n, vector<vector<int>> &arr)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][j] != 0)
            arr[i][j] = -1;
    }
}

vector<vector<int>> setZero(vector<vector<int>> &arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                markRow(i, m, arr);
                markCol(j, n, arr);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == -1)
                arr[i][j] = 0;
        }
    }

    return arr;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    arr = setZero(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> setZero(vector<vector<int>> &arr, int n, int m)
{
    int col[m] = {0};
    int row[n] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                arr[i][j] = 0;
            }
        }
    }
    return arr;
}*/
vector<vector<int>> setZero(vector<vector<int>> &arr, int n, int m)
{
    int col[m] = {0};
    int row[n] = {0};
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            arr[i][0] = 0;
            if (j != 0)
            {
                arr[0][j] = 0;
            }
            else
            {
                col0 = 0;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (arr[i][j] == 0){
                arr[i][0]=0;
                arr[0][j]=0;
            }
        }
    }
    if(col0 == 0){
        for(int i=0; i<n; i++){
            arr[i][0] = 0;
        }
    }
    if(arr[0][0] == 0){
        for(int j=0; j<m; j++){
            arr[0][j] = 0;
        }
    }
    return arr;
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    arr = setZero(arr, n, m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}