#include <bits/stdc++.h>
using namespace std;

bool amastrong(int data)
{
    int duplicate = data;
    int sum = 0;
    int rev =0;
    while (data > 0)
    {
        int ld = data % 10;
        sum = sum + (ld * ld * ld);
        data = data / 10;
        rev = (rev *10) +ld;

    }
    if (sum == duplicate)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    int n;
    cin >> n;

    bool amstrong = amastrong(n);
    if (!amstrong)
    {
        cout << "not an amstrong ";
    }
    else
    {
        cout << "amstrong";
    }
}