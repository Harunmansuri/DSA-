#include <bits/stdc++.h>
using namespace std;

/*int hcf(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return hcf(b, a % b);
}*/

int hcf(int a, int b)
{
    int gcd = 1;
    for (int i = 1; i <= min(a, b); i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            gcd = i;//tc 0(min(n1,n2))
        }
    }
    return gcd;

    /*for (int i = min(a, b); i >= 1; i--)
    {
        if (a % i == 0 && b % i == 0)
        {   
            gcd = i;//tc 0(min(n1,n2))
            break; 
        } 
    } 
    return gcd;

    */
}
int main()
{
    int a;
    int b;
    cin >> a >> b;
    int result = hcf(a, b);
    cout<<"HCF of " << a << " and " << b << " is " << result << endl;
    return 0;
}
// full form of  hcf is highest common factor
//  full form of gcd is greatest common divisor