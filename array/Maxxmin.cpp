#include <bits/stdc++.h>
using namespace std;

int getmin(int nums[], int size) {
    int minVal = INT_MAX;
    for(int i=0; i<size; i++){
        if(nums[i] < minVal){
            minVal = nums[i];
        }
    }
    return minVal;
}

int getmax(int nums[], int size) {
    int maxVal = INT_MIN;
    for(int i=0; i<size; i++){
      maxVal = max(maxVal, nums[i]);
       // if(nums[i] > maxVal){
         //   maxVal = nums[i];
       // }
    }
    return maxVal;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    int nums[n];
    cout << "Enter the array elements: ";   // ✅ ab yeh ek hi baar print hoga
    for(int i=0; i<n; i++){
        cin >> nums[i];
    }

    int minVal = getmin(nums, n);
    cout << "Min number is " << minVal << endl;

    int maxVal = getmax(nums, n);
    cout << "Max number is " << maxVal << endl;

    return 0;
}
// Find the maximum and minimum element in an array