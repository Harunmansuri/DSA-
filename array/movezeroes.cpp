#include <iostream>
#include <vector>
using namespace std;

/*void moveZeroes(vector<int> &arr) {
    int n = arr.size();
    int start = 0, end = n - 1;

    while (start <= end) {
        if (arr[start] != 0) {
            start++;
        } else if (arr[end] == 0) {
            end--;
        } else {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }
}*/

void moveZeroes(vector<int> &arr) {
    int n = arr.size();
    int j = 0; // pointer for placing non-zero elements

    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    moveZeroes(arr);
    for (int x : arr) cout << x << " ";
    return 0;
}
