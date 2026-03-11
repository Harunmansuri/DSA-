#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> threesum(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
        {
            continue;
        }
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
             while (j < k && arr[j] == arr[j-1])
                {
                    j++;
                }
                while (arr[k] == arr[k + 1] && j < k)
                    k--;
            }
        }
    }
    return ans;
}

int main()
{
    string s;
    getline(cin, s);
    stringstream ss(s);
    vector<int> arr;
    int num;
    while (ss >> num)
    {
        arr.push_back(num);
    }

    int n = arr.size();
    vector<vector<int>> ans = threesum(arr, n);
    for(auto x : ans){
        for(auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
}

/*
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& arr, int n)
{
    set<vector<int>> st; // duplicate avoid

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            for(int k = j + 1; k < n; k++)
            {
                if(arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    string s;
    getline(cin,s);

    stringstream ss(s);

    vector<int> arr;
    int num;

    while(ss >> num)
    arr.push_back(num);

    int n = arr.size();

    vector<vector<int>> ans = threeSum(arr,n);

    for(auto it : ans)
    {
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
    }
}
   
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int>& arr, int n)
{
    set<vector<int>> st;

    for(int i = 0; i < n; i++)
    {
        set<int> hashset;

        for(int j = i+1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]);

            if(hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }

            hashset.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    string s;
    getline(cin,s);

    stringstream ss(s);

    vector<int> arr;
    int num;

    while(ss >> num)
    arr.push_back(num);

    int n = arr.size();

    vector<vector<int>> ans = threeSum(arr,n);

    for(auto it : ans)
    cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
}


*/