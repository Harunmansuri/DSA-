#include<bits/stdc++.h>
using namespace std;

void mergeArrays(const vector<int>& arr1, const vector<int>& arr2, vector<int>& arr3) {
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < n) {
        arr3[k++] = arr1[i++];
    }
    while (j < m) {
        arr3[k++] = arr2[j++];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;
    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> arr3(n + m);
    mergeArrays(arr1, arr2, arr3);

    for (int i = 0; i < n + m; i++) {
        cout << arr3[i] << " ";
    }
    return 0;
}
