#include <bits/stdc++.h>
using namespace std;

/*
    Function: nextPermutation
    Purpose: Find next lexicographical permutation
    Time Complexity: O(N)
    Space Complexity: O(1)
*/

// Manual reverse function
void reverseArray(vector<int> &arr, int start, int end) {
    while(start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

vector<int> nextPermutation(vector<int> &arr) {
    
    int n = arr.size();
    int index = -1;

    // Step 1: Find first decreasing element from right
    for(int i = n - 2; i >= 0; i--) {
        if(arr[i] < arr[i + 1]) {
            index = i;
            break;
        }
    }

    // Step 2: If no breakpoint, reverse whole array
    if(index == -1) {
        reverseArray(arr, 0, n - 1);
        return arr;
    }

    // Step 3: Find element just greater than arr[index]
    for(int i = n - 1; i > index; i--) {
        if(arr[i] > arr[index]) {
            swap(arr[i], arr[index]);
            break;
        }
    }

    // Step 4: Reverse right half manually
    reverseArray(arr, index + 1, n - 1);

    return arr;
}

int main() {

    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = nextPermutation(arr);

    for(int num : result) {
        cout << num << " ";
    }

    return 0;
}
/*
❌ Mistakes in Your Code:

for(int i=n-2; i<=0; i--) → ye kabhi chalega hi nahi
✔ Condition hona chahiye i >= 0

for(int i=n-1; i>= index; i--)
✔ Yaha i > index hona chahiye

Last me pura array reverse kar diya
✔ Sirf index+1 se end tak reverse karna hota hai

Output me arr[i] print kar rahe ho instead of ans[i]*/