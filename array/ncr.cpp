#include <iostream>
using namespace std;


// returns factorial of n 
long factorial(int n)
{
    if(n==0) return 1;
    long res = 1;
    for (int i = 2; i <= n; i++)
    {
        res = res * i;
    }
    return res;
}
long nCr(int n, int r)
{
    long num = factorial(n);
    long denom = (factorial(r) * factorial(n - r));
    return num / denom;
}
//driver code
int main()
{
    int n = 5;
    int r = 3;
    long ncrresult = nCr(n,r);
    cout << "ncr result is" << ncrresult<<endl;
    return 0;
}