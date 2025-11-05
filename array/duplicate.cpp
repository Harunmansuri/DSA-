#include <bits/stdc++.h>
using namespace std;

/*[Naive Approach] Using Nested Loop - O(n^2) Time and O(1) Space
[Better Approach - 1] Sorting with Consecutive Comparison - O(n log n) Time and O(1) Space
[Better Approach - 2] Using Frequency Array - O(n) Time and O(n) Space
[Expected Approach] Negative Marking approach - O(n) Time and O(1) Space*/
// For multiple duplicate elements
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        int x = abs(nums[i]);
        if (nums[x - 1] < 0) {
            ans.push_back(x);
        }
        nums[x - 1] = -nums[x - 1];
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> ans = findDuplicates(nums);

    if (ans.empty()) {
        cout << "No duplicates found" << endl;
    } else {
        cout << "Duplicates: ";
        for (int x : ans) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}
/*#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDuplicates(vector<int>& arr) {
    
    // sort the array so that duplicates are adjacent
    sort(arr.begin(), arr.end());

    vector<int> ans;

    // traverse the sorted array and check 
    // for consecutive duplicates
    for(int i = 1; i < arr.size(); i++){
        
        // tf current element is same as previous
        if(arr[i] == arr[i - 1]){

            // aoid adding the same duplicate multiple times
            if(ans.empty() || ans.back() != arr[i]){
                ans.push_back(arr[i]);
            }
        }
    }

    return ans;
}

int main() {

    vector<int> arr = {2, 3, 1, 2, 3};

    vector<int> res = findDuplicates(arr);

    for(int ele : res){
        cout << ele << ' ';
    }
    cout << endl;

    return 0;
}
    



#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& arr) {
    
    int n = arr.size();
    // frequency array of size n+1 (1-based indexing)
    vector<int> freq(n + 1, 0);  
    vector<int> ans;

    // Ccount frequencies using the array
    for (int num : arr) {
        freq[num]++;
    }

    // collect elements that appear exactly twice
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 2) {
            ans.push_back(i);
        }
    }

    return ans;
}

int main() {
    
    vector<int> arr = {2, 3, 1, 2, 3};  
    vector<int> res = findDuplicates(arr);

    for (int ele : res) {
        cout << ele << ' ';
    }
    cout << endl;

    return 0;
}
    
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDuplicates(vector<int>& arr) {
    
    // sort the array so that duplicates are adjacent
    sort(arr.begin(), arr.end());

    vector<int> ans;

    // traverse the sorted array and check 
    // for consecutive duplicates
    for(int i = 1; i < arr.size(); i++){
        
        // tf current element is same as previous
        if(arr[i] == arr[i - 1]){

            // aoid adding the same duplicate multiple times
            if(ans.empty() || ans.back() != arr[i]){
                ans.push_back(arr[i]);
            }
        }
    }

    return ans;
}

int main() {

    vector<int> arr = {2, 3, 1, 2, 3};

    vector<int> res = findDuplicates(arr);

    for(int ele : res){
        cout << ele << ' ';
    }
    cout << endl;

    return 0;
}*/