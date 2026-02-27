#include <bits/stdc++.h>
using namespace std;

int main()
{

    int number;
    cin >> number; // reads integer input
    vector<int> arr;
    for (int i = 0; i < number; i++)
    {
        //cin >> arr[i];
        int num;
        cin>>num;
        arr.push_back(num);
    }
    for (auto it : arr)
    {
        cout << it;
    }

    return 0;
    
}