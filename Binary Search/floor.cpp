#include<bits/stdc++.h>
using namespace std;

// function to find floor index using binary search
int floorElement(vector<int> &arr, int x){

    int n = arr.size();        // array size
    int low = 0;               // start index
    int high = n - 1;          // end index

    int ans = -1;              // possible floor index

    // binary search
    while(low <= high){

        // mid calculate
        int mid = low + (high - low) / 2;

        // agar element x se chhota ya equal hai
        if(arr[mid] <= x){

            ans = mid;         // possible floor store
            low = mid + 1;     // right side search (better floor)

        }
        else{

            // agar element bada hai
            // floor left side me hoga
            high = mid - 1;

        }
    }

    return ans;                // final floor index
}

int main(){

    string s;

    // -------- ARRAY INPUT USING GETLINE --------
    getline(cin, s);           // poori line read karega

    stringstream ss(s);        // string ko numbers me convert karega
    vector<int> arr;

    int num;

    // numbers extract karke vector me push
    while(ss >> num){
        arr.push_back(num);
    }

    // -------- X INPUT --------
    int x;
    cin >> x;

    // function call
    int ans = floorElement(arr, x);

    cout << ans;

}