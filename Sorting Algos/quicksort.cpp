#include <bits/stdc++.h>
using namespace std;

/*
 Partition function
 - First element ko pivot maana hai
 - Hoare style partition
*/
int partition(vector<int> &arr, int start, int end) {
    int pivot = arr[start];   // FIRST element as pivot
    int i = start;
    int j = end;

    while (i < j) {

        // left side se pivot se chhota ya equal dhundho
        while (i <= end && arr[i] <= pivot) {
            i++;
        }

        // right side se pivot se bada element skip karo
        while (j >= start && arr[j] > pivot) {
            j--;
        }

        // agar i abhi bhi j se chhota hai to swap
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // pivot ko uski correct position pe le aao
    swap(arr[start], arr[j]);

    return j;   // pivot index return
}

/*
 Quick Sort function
*/
void quicksort(vector<int> &arr, int start, int end) {
    // base case
    if (start < end) {
        int p = partition(arr, start, end);

        // left subarray
        quicksort(arr, start, p - 1);

        // right subarray
        quicksort(arr, p + 1, end);
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quicksort(arr, 0, n - 1);

    // print sorted array
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
