#include <bits/stdc++.h>
using namespace std;

/*vector<int> findUnion(vector<int> &arr1, vector<int> &arr2)
{

    set<int> st;
    for (int x : arr1)
    {
        st.insert(x);
    }
    for (int x : arr2)
    {
        st.insert(x);
    }
    // move set elemets to vetcor
    vector<int> result(st.begin(), st.end());
    return result;
    //union[st.size()]
    vector<int > unionARR(n);

    
    i=0;
    for(auto it:st){ 
    union[i++] = it;
    }
    return unionARR;
}
*/

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<int> arr1, arr2;

    stringstream ss1(s1);
    int num;
    while (ss1 >> num)
    {
        arr1.push_back(num);
    }

    stringstream ss2(s2);

    while (ss2 >> num)
    {
        arr2.push_back(num);
    }

    // Print the elements

    vector<int> ans = findUnion(arr1, arr2);

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}