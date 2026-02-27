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
}*/

vector<int> findUnion(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int i=0;
    int j=0;
    vector<int> Union;
    while(i<n1 && j<n2){
        if(arr1[i]<= arr2[j]){
            if(Union.size() == 0 || Union.back() != arr1[i]){
                 Union.push_back(arr1[i]);
            }
            i++;
        }
        else{
            if(Union.size() == 0 || Union.back() != arr2[j]){
                 Union.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i<n1){
         if(Union.size() == 0 || Union.back() != arr1[i]){
                 Union.push_back(arr1[i]);
            }
            i++;
    }
    while(j<n2){
         if(Union.size() == 0 || Union.back() != arr2[j]){
                 Union.push_back(arr2[j]);
            }
            j++;
    }
    return Union;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<int> arr1, arr2;
    string num;
    stringstream ss1(s1);
    while (getline(ss1, num, ','))
    {
        arr1.push_back(stoi(num));
    }
    stringstream ss2(s2);
    while (getline(ss2, num, ','))
    {
        arr2.push_back(stoi(num));
    }
    // 🔹 Function Call
    vector<int> result = findUnion(arr1, arr2);

    // 🔹 Print result
    for (int x : result)
    {
        cout << x << " ";
    }
    return 0;
}
//worked for only sorted arrays, for unsorted arrays we can use set data structure to store unique elements and then move them to vector.