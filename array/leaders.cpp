#include<bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &arr, int n){
    bool leader;
    vector<int> ans;

    for(int i = 0; i < n; i++){
        leader = true;

        for(int j = i + 1; j < n; j++){
            if(arr[j] > arr[i]){
                leader = false;
                break;
            }
        }

        if(leader == true){
            ans.push_back(arr[i]);
        }
    }

    return ans;   // ✅ very important
}

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    vector<int> ans = leaders(arr, n);

    for(int i = 0; i < ans.size(); i++){   // ✅ use ans.size()
        cout << ans[i] << " ";
    }
}
