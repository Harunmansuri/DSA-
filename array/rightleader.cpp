#include <bits/stdc++.h>
using namespace std;

int leadersCnt(vector<int> &arr){
    int n = arr.size();

    int cnt=1;
    int maxi = arr[0];
    for(int i=1; i<n; i++){
         if(arr[i] > maxi){
             cnt++;
             maxi = arr[i];
         }
    }
    return cnt;

}
int main()
{
    string s;
    getline(cin, s);

    vector<int> arr;
    string num = "";
    for (char ch : s)
    {
        if (isdigit(ch) || ch == '-')
        {
            num += ch;
        }
        else
        {
            if (num != "")
            {
                arr.push_back(stoi(num));
                num = "";
            }
        }
    }
    if (num != "")
    {
        arr.push_back(stoi(num));
    }

    int ans = leadersCnt(arr);
    cout << ans << endl;
    // Print result
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}

/*
int leadersCnt(vector<int> &arr) {
    int n = arr.size();
    int cnt = 0;

    for(int i = 0; i < n; i++) {
        bool isLeader = true;

        for(int j = i+1; j < n; j++) {
            if(arr[j] > arr[i]) {
                isLeader = false;
                break;
            }
        }

        if(isLeader) cnt++;
    }

    return cnt;
}*/
/*
int leadersCnt(vector<int> &arr) {
    int n = arr.size();
    int cnt = 0;

    int maxi = INT_MIN;

    for(int i = n-1; i >= 0; i--) {
        if(arr[i] >= maxi) {
            cnt++;
            maxi = arr[i];
        }
    }

    return cnt;
}*/
/*
vector<int> leaders(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans;

    int maxi = INT_MIN;

    for(int i = n-1; i >= 0; i--) {
        if(arr[i] >= maxi) {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}*/
/*
#include <bits/stdc++.h>
using namespace std;

vector<int> findLeaders(vector<int> &arr) {
    int n = arr.size();
    vector<int> ans;

    int maxi = INT_MIN;

    // Right se traverse
    for(int i = n-1; i >= 0; i--) {
        if(arr[i] >= maxi) {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }

    // Reverse kyunki humne right se dala hai
    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string s;
    getline(cin, s);

    vector<int> arr;
    string num = "";

    // String se numbers extract karne ka TCS ready tarika
    for(char ch : s) {
        if(isdigit(ch) || ch == '-') {
            num += ch;
        } else {
            if(num != "") {
                arr.push_back(stoi(num));
                num = "";
            }
        }
    }
    if(num != "") {
        arr.push_back(stoi(num));
    }

    vector<int> leaders = findLeaders(arr);

    // Print leaders
    for(int x : leaders) {
        cout << x << " ";
    }

    return 0;
}*/