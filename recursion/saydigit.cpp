#include <bits/stdc++.h>
using namespace std;

void saydigit(int n, string arr[])
{
    // base case
    if (n == 0)
    {
        return;
    }

    // recursive call first
    int digit = n % 10;
    n = n / 10;
    saydigit(n, arr);

    // processing after recursion (correct order)
    cout << arr[digit] << " ";
}

int main()
{
    string arr[10] = {
        "zero", "one", "two", "three", "four",
        "five", "six", "seven", "eight", "nine"};

    int n;
    cin >> n;

    // special case if input is 0
    if (n == 0)
    {
        cout << "zero";
    }
    else
    {
        saydigit(n, arr);
    }

    cout << endl;
    return 0;
}
