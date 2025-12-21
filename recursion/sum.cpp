#include <bits/stdc++.h>
using namespace std;


int sum(int n, int allsum){
    if(n<1){
        return allsum;

    }
    return sum(n-1,allsum+n);
}

int main()
{
    int n;
    cin >> n;

   int result = sum(n, 0);
    cout << result << endl;
    return 0;
}