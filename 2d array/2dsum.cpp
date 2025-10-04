#include <bits/stdc++.h>
using namespace std;

int maxrowsum(int arr[3][3], int n, int m)
{
    int maxi = INT_MIN;
    int rowno = -1;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum = sum + arr[i][j];
        }
        if (sum > maxi)
        {
            maxi= sum;
            rowno = i;
        }
    }
    cout << "the maximum sum is maxrow:" << maxi << " ";
    return rowno;
}
/*int rowsum(int arr[3][3], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum = sum + arr[i][j];
        }
        cout << sum << endl;
    }
    cout << endl;
}
int colsum(int arr[3][3], int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum = sum + arr[j][i];
        }
        cout << sum << endl;
    }
    cout << endl;
*/
int main()
{
    int arr[3][3]; // declaration

    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,0,1,1};
    // taking row wise input
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cin >> arr[row][col];
        }
    }

    // print
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    /*int sum = rowsum(arr, 3, 3);
    cout << "sum of each row is:-" << sum << endl;

    int sum2 = colsum(arr, 3, 3);
    cout << "sum of each column is:-" << sum2 << endl*/
    int ansindex = maxrowsum(arr,3,3);
    cout<<"the maximum sum is "<< ansindex <<endl;
    return 0;
}