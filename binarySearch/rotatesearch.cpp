#include<bits/stdc++.h>
using namespace std;
int rotatedBinarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        }
        // Check if the left half is sorted
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target < arr[mid]) {
                high = mid - 1;  // Search in the left half
            } else {
                low = mid + 1;   // Search in the right half
            }
        } else {
            // Right half is sorted
            if (arr[mid] < target && target <= arr[high]) {
                low = mid + 1;   // Search in the right half
            } else {
                high = mid - 1;  // Search in the left half
            }
        }
    }
    return -1;  // Target not found
}
int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = rotatedBinarySearch(arr, target);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}