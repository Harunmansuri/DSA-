/*
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    // rows and columns input
    cin >> n >> m;

    cin.ignore(); // remove leftover newline before getline

    vector<vector<int>> arr(n, vector<int>(m));

    // -------- INPUT USING GETLINE --------
    for(int i = 0; i < n; i++)
    {
        string s;

        getline(cin, s); // read entire row

        stringstream ss(s); // convert string to stream

        for(int j = 0; j < m; j++)
        {
            ss >> arr[i][j]; // extract numbers
        }
    }


    // -------- REVERSE EACH ROW USING SWAP --------
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m/2; j++)
        {
            // swap first element with last element
            swap(arr[i][j], arr[i][m-1-j]);
        }
    }

    // -------- PRINT MATRIX --------
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;

    // rows aur columns input
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    // -------- MATRIX INPUT --------
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    // -------- REVERSE EACH ROW --------
    for(int i = 0; i < n; i++)
    {
        int l = 0;          // left pointer
        int r = m - 1;      // right pointer

        while(l < r)
        {
            // swap first and last elements
            swap(arr[i][l], arr[i][r]);

            l++;
            r--;
        }
    }


    // -------- PRINT MATRIX --------
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}
    #include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    // input
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // transpose
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // reverse using STL
    for(int i = 0; i < n; i++)
    {
        reverse(arr[i].begin(), arr[i].end());
    }

    // print
    for(auto &row : arr)
    {
        for(auto &x : row)
        {
            cout << x << " ";
        }
        cout << endl;
    }
}
    #include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    // -------- INPUT --------
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // -------- STEP 1 : TRANSPOSE --------
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            // swap row and column
            swap(arr[i][j], arr[j][i]);
        }
    }

    // -------- STEP 2 : REVERSE EACH ROW --------
    for(int i = 0; i < n; i++)
    {
        int l = 0;
        int r = n - 1;

        while(l < r)
        {
            swap(arr[i][l], arr[i][r]);
            l++;
            r--;
        }
    }

    // -------- PRINT MATRIX --------
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


TIME COMPLEXITY  : O(n^2)
SPACE COMPLEXITY : O(1)

Explanation:
1. Matrix ka transpose kiya (row ↔ column)
2. Har row ko reverse kiya
Isse matrix 90° clockwise rotate ho jata hai.

TIME COMPLEXITY  : O(n^2)
SPACE COMPLEXITY : O(1)

Explanation:
Transpose ke baad STL reverse() use karke row reverse kar di.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;
    cin.ignore(); // newline remove

    vector<vector<int>> arr(n, vector<int>(m));

    // -------- INPUT USING GETLINE --------
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);

        stringstream ss(s);

        for (int j = 0; j < m; j++)
        {
            ss >> arr[i][j];
        }
    }

    // -------- STEP 1 : TRANSPOSE MATRIX --------
    // swap upper triangle with lower triangle
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < m; j++)
        {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // -------- STEP 2 : REVERSE EACH ROW --------
    for(int i = 0; i < n; i++)
    {
        int l = 0;
        int r = n - 1;

        while(l < r)
        {
            swap(arr[i][l], arr[i][r]);
            l++;
            r--; // ✔ correct
        }
    }

    // -------- PRINT MATRIX --------
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}