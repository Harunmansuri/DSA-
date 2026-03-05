
/*#include <bits/stdc++.h>
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

vector<int> intersection(vector<int>& nums1 , vector<int>& nums2){
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
}

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
}*/

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> ans;
    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size())
    {
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else if (arr1[i] > arr2[j])
        {

            j++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    string s1;
    string s2;
    getline(cin, s1);
    getline(cin, s2);

    vector<int> arr1, arr2;
    string num = "";
    for (char ch : s1)
    {
        if (isdigit(ch) || ch == '-')
        {
            num += ch;
        }
        else
        {
            if (!num.empty())
            {
                arr1.push_back(stoi(num));
                num = "";
            }
        }
    }
    if (!num.empty())
    {
        arr1.push_back(stoi(num));
    }
    num = "";
    for (char ch : s2)
    {
        if (isdigit(ch) || ch == '-')
        {
            num += ch;
        }
        else
        {
            if (!num.empty())
            {
                arr2.push_back(stoi(num));
                num = "";
            }
        }
    }
    if (!num.empty())
    {
        arr2.push_back(stoi(num));
    }

    vector<int> result = intersection(arr1, arr2);

    for (int it : result)
    {
        cout << it<<" ";
    }

    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &a, vector<int> &b) {

    vector<int> ans;

    for (int i = 0; i < a.size(); i++) {

        for (int j = 0; j < b.size(); j++) {

            if (a[i] == b[j]) {

                // Unique check
                if (ans.empty() || find(ans.begin(), ans.end(), a[i]) == ans.end())
                    ans.push_back(a[i]);

                break;
            }
        }
    }

    return ans;
}

int main() {

    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    vector<int> arr1, arr2;
    string num = "";

    // Parse first array
    for (char ch : line1) {
        if (isdigit(ch) || ch == '-') num += ch;
        else {
            if (!num.empty()) {
                arr1.push_back(stoi(num));
                num = "";
            }
        }
    }

    num = "";

    // Parse second array
    for (char ch : line2) {
        if (isdigit(ch) || ch == '-') num += ch;
        else {
            if (!num.empty()) {
                arr2.push_back(stoi(num));
                num = "";
            }
        }
    }

    vector<int> result = intersection(arr1, arr2);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]";

  🥇 1️⃣ BRUTE FORCE APPROACH
⏱ Time: O(n*m)
🧠 Space: O(1) (excluding result)

}*/


/*
🥈 2️⃣ SORTING + TWO POINTER APPROACH
⏱ Time: O(n log n + m log m)
🧠 Space: O(1) extra

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &a, vector<int> &b) {

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i = 0, j = 0;
    vector<int> ans;

    while (i < a.size() && j < b.size()) {

        if (a[i] < b[j]) i++;
        else if (a[i] > b[j]) j++;
        else {

            if (ans.empty() || ans.back() != a[i])
                ans.push_back(a[i]);

            i++;
            j++;
        }
    }

    return ans;
}

int main() {

    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    vector<int> arr1, arr2;
    string num = "";

    for (char ch : line1) {
        if (isdigit(ch) || ch == '-') num += ch;
        else if (!num.empty()) {
            arr1.push_back(stoi(num));
            num = "";
        }
    }

    num = "";

    for (char ch : line2) {
        if (isdigit(ch) || ch == '-') num += ch;
        else if (!num.empty()) {
            arr2.push_back(stoi(num));
            num = "";
        }
    }

    vector<int> result = intersection(arr1, arr2);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]";
}
*/
/*
🥇 3️⃣ HASHSET APPROACH (BEST FOR UNSORTED)
⏱ Time: O(n + m)
🧠 Space: O(n)
#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &a, vector<int> &b) {

    unordered_set<int> s(a.begin(), a.end());
    unordered_set<int> resultSet;

    for (int num : b) {
        if (s.find(num) != s.end()) {
            resultSet.insert(num);
        }
    }

    vector<int> ans(resultSet.begin(), resultSet.end());
    sort(ans.begin(), ans.end());   // optional

    return ans;
}

int main() {

    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    vector<int> arr1, arr2;
    string num = "";

    for (char ch : line1) {
        if (isdigit(ch) || ch == '-') num += ch;
        else if (!num.empty()) {
            arr1.push_back(stoi(num));
            num = "";
        }
    }

    num = "";

    for (char ch : line2) {
        if (isdigit(ch) || ch == '-') num += ch;
        else if (!num.empty()) {
            arr2.push_back(stoi(num));
            num = "";
        }
    }

    vector<int> result = intersection(arr1, arr2);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]";
}

*/

/*

#include <bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int> &a, vector<int> &b) {

    set<int> s1(a.begin(), a.end());   // sorted + unique
    set<int> result;

    for (int num : b) {
        if (s1.find(num) != s1.end()) {
            result.insert(num);
        }
    }

    vector<int> ans(result.begin(), result.end());
    return ans;
}

int main() {

    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    vector<int> arr1, arr2;
    string num = "";

    // Parse first
    for (char ch : line1) {
        if (isdigit(ch) || ch == '-') num += ch;
        else if (!num.empty()) {
            arr1.push_back(stoi(num));
            num = "";
        }
    }

    num = "";

    // Parse second
    for (char ch : line2) {
        if (isdigit(ch) || ch == '-') num += ch;
        else if (!num.empty()) {
            arr2.push_back(stoi(num));
            num = "";
        }
    }

    vector<int> result = intersection(arr1, arr2);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]";
}
*/
/*
🥇 5️⃣ FREQUENCY MAP APPROACH (Using unordered_map)

👉 Useful jab duplicate count bhi manage karna ho
👉 Abhi unique result hi return kar rahe hain

⏱ Time: O(n + m)
🧠 Space: O(n)
#include <bits/stdc++.h>
using namespace std;
// Note: This approach can be easily modified to return duplicates as well by not setting freq[num] to 0 and just decrementing it.

vector<int> intersection(vector<int> &a, vector<int> &b) {

    unordered_map<int,int> freq;
    vector<int> ans;

    // Count frequency of arr1
    for (int num : a) {
        freq[num]++;
    }

    // Traverse arr2
    for (int num : b) {

        if (freq[num] > 0) {

            // Unique add
            if (ans.empty() || find(ans.begin(), ans.end(), num) == ans.end())
                ans.push_back(num);

            freq[num] = 0;  // avoid duplicate
        }
    }

    sort(ans.begin(), ans.end()); // optional
    return ans;
}

int main() {

    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    vector<int> arr1, arr2;
    string num = "";

    for (char ch : line1) {
        if (isdigit(ch) || ch == '-') num += ch;
        else if (!num.empty()) {
            arr1.push_back(stoi(num));
            num = "";
        }
    }

    num = "";

    for (char ch : line2) {
        if (isdigit(ch) || ch == '-') num += ch;
        else if (!num.empty()) {
            arr2.push_back(stoi(num));
            num = "";
        }
    }

    vector<int> result = intersection(arr1, arr2);

    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ",";
    }
    cout << "]";
}
*/

/*
#include <bits/stdc++.h>
using namespace std;

/*
=========================================
INTERSECTION WITH DUPLICATES
Using Frequency Map (Best Approach)
Time: O(n + m)
Space: O(n)
=========================================
*/
/*
vector<int> intersection(vector<int> &a, vector<int> &b) {

    unordered_map<int,int> freq;
    vector<int> ans;

    // Step 1: Count frequency of first array
    for (int num : a) {
        freq[num]++;
    }

    // Step 2: Traverse second array
    for (int num : b) {

        // If element exists and frequency > 0
        if (freq[num] > 0) {
            ans.push_back(num);
            freq[num]--;   // Decrease count (important for duplicates)
        }
    }

    return ans;
}

int main() {

    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);

    vector<int> arr1, arr2;
    string num = "";

    // ===== Parse First Array =====
    for (char ch : line1) {
        if (isdigit(ch) || ch == '-') {
            num += ch;
        } 
        else {
            if (!num.empty()) {
                arr1.push_back(stoi(num));
                num = "";
            }
        }
    }

    num = "";

    // ===== Parse Second Array =====
    for (char ch : line2) {
        if (isdigit(ch) || ch == '-') {
            num += ch;
        } 
        else {
            if (!num.empty()) {
                arr2.push_back(stoi(num));
                num = "";
            }
        }
    }

    vector<int> result = intersection(arr1, arr2);

    // Print in [ ] format
    cout << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1)
            cout << ",";
    }
    cout << "]";

    return 0;
}*/