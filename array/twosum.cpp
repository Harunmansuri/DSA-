#include <bits/stdc++.h>
using namespace std;


/*1 approuch 2 pass hastable 
2 one pass hastable 
o(n2) solution 
sort and two pointer solution
*/

vector<int> twosum(vector<int>& arr, int target, int n) {
    //one pass solution
   /* unordered_map<int, int> mp; 
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int complement = target - num;
        if (mp.find(complement) != mp.end()) {
            return {mp[complement], i}; // return indices of the pair
        }
        mp[num] = i; 
    }
    return {}; // no pair found*/

   /*
   o(n2) solution
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]+arr[j] == target){
                return {i,j};
            }
        }
       
    }
    return {};*/
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int target;
    cin >> target;

    vector<int> ans = twosum(arr, target, n);
    if (!ans.empty()) {
        cout << ans[0] << " " << ans[1] << endl; 
    } else {
        cout << "No pair found" << endl;
    }

    return 0;
}
