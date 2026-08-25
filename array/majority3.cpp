#include <bits/stdc++.h>
using namespace std;

vector<int> majority(vector<int> &arr, int n)
{
    int count1 = 0;
    int count2 = 0;
    int element1 = INT_MIN;
    int element2 = INT_MIN;
    for(int i=0; i<n; i++){
        if((count1 ==0)  && element2 != arr[i]){
            count1=1;
            element1=arr[i];
        }
        else if((count2 ==0)  && element1 != arr[i]){
             count2=1;
            element2=arr[i];
        }
        else if(arr[i]==element1){
            count1++;
        }
        else if(arr[i]==element2){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }
    vector<int>ans;
    count1=0;
    count2=0;
    for(int i=0; i<n; i++){
        if(arr[i]==element1){
            count1++;
        }
        else if(arr[i]==element2){
            count2++;
        }
    }
    int mini = n/3+1;
    if(count1>=mini){
        ans.push_back(element1);
    }
    if(count2>=mini){
        ans.push_back(element2);
    }
    sort(ans.begin(), ans.end());
    return ans;

}
int main()
{
    string s;
    getline(cin, s);
    vector<int> arr;

    string nums = "";
    for (char ch : s)
    {
        if (isdigit(ch) || ch == '-')
        {
            nums += ch;
        }
        else
        {
            if (!nums.empty())
            {
                arr.push_back(stoi(nums));
                nums = "";
            }
        }
    }
    if (!nums.empty())
    {
        arr.push_back(stoi(nums));
        nums = "";
    }
    int n = arr.size();
    vector<int> ans = majority(arr,n);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" "<<endl;
    }
}