#include <bits/stdc++.h>

using namespace std;

/*void displayDivisors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";//o(n)
        }
    }
    cout << endl;
}*/
void displayDivisors(int n)

{
    vector<int> list;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            list.push_back(i);
            if ((n / i) != i)
            {
                list.push_back(n / i);
            }
        }
    }
    sort(list.begin(), list.end());
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    displayDivisors(n);
    return 0;
}