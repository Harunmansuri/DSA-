#include <bits/stdc++.h>
using namespace std;


/*int sum(int n, int allsum)//parameterized recursion
{
    if(n<1){
        return allsum;

    } 
    return sum(n-1,allsum+n); 
}
*/

int sum(int n)//functional recursion
{
    if(n==1){
        return 1;

    }
    if(n==0){
        return 0; 
    }
    return n+sum(n-1);
}
int main()
{
    int n;
    cin >> n;

   int result = sum(n);
    cout << result << endl;
    return 0;
}