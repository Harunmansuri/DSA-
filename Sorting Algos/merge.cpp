#include <bits/stdc++.h>
using namespace std;

// Merge two sorted parts of the array
void merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> temp;   // temporary array

    int i = left;       // left subarray pointer
    int j = mid + 1;    // right subarray pointer

    // Compare both parts and store smaller element
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements of left part
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    // Copy remaining elements of right part
    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }

    // Copy temp array back to original array
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }
}

// Merge Sort function
void mergeSort(vector<int> &arr, int left, int right) {
    // Base condition
    if (left >= right) return;

    int mid = (left + right) / 2;

    // Sort left half
    mergeSort(arr, left, mid);

    // Sort right half
    mergeSort(arr, mid + 1, right);

    // Merge both halves
    merge(arr, left, mid, right);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
/*
void merge(vector<int> &arr, int left, int mid, int right) {
    vector<int> temp;

    int i = left;     // left subarray pointer
    int j = mid + 1;  // right subarray pointer

    // Merge both sorted parts
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    // Copy remaining elements
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    // 🔴 Copy temp back using direct index pointer
    int index = left;   // start writing from left position
    for (int x : temp) {
        arr[index] = x;
        index++;
    }
}
*/