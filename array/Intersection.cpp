#include <bits/stdc++.h>
using namespace std;


vector<int> intersection(vector<int>& nums1 , vector<int>& nums2){
    vector<int>ans;
        unordered_set<int>st(begin(nums1),end(nums1));
        unordered_set<int>st2(begin(nums2),end(nums2));

        for(auto &it:st2){
            if(st.find(it)!=st.end()){
                ans.push_back(it);
            }
        }
        return reverse(ans.begin(), ans.end()), ans;
}

/*vector<int> intersection(vector<int>& nums1 , vector<int>& nums2){
    vector<int> ans;
    int n1 = nums1.size();
    int n2 = nums2.size();
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    int i = 0, j = 0;
    
    while(i < n1 && j < n2){
        if(nums1[i] == nums2[j]){
            if(ans.empty() || ans.back() != nums1[i]){   // avoid duplicates
                ans.push_back(nums1[i]);
            }
            i++;
            j++;
        }
        else if(nums1[i] < nums2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;   // ✅ missing in your code
}*/

int main(){
    int n1;
    cout << "Enter the size of array 1: ";
    cin >> n1;

    int n2;
    cout << "Enter the size of array 2: ";   // ✅ corrected
    cin >> n2;

    vector<int> nums1(n1);
    cout << "Enter elements of array 1: ";
    for(int i=0; i<n1; i++){
        cin >> nums1[i];
    }

    vector<int> nums2(n2);
    cout << "Enter elements of array 2: ";
    for(int i=0; i<n2; i++){
        cin >> nums2[i];
    }

    vector<int> ans = intersection(nums1, nums2);

    if(ans.empty()){
        cout << "No similar element found";
    }
    else{
        cout << "Intersecting elements: ";
        for(int x: ans){
            cout << x << " ";
        }
    }
    return 0;  // ✅ good practice
}
