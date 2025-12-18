#include <iostream>
using namespace std;

void displayDivisors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";//o(n)
        }
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