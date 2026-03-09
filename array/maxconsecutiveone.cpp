#include <bits/stdc++.h>
using namespace std;



int maxConsecutive(vector<int> &arr){
    int n = arr.size();

    int maxi=0;
    for(int i=0; i<n; i++){
        int cnt=0; 
        for(int j=1; j<n; j++){
            if(arr[i]==1){
                cnt++;
                maxi = max(maxi,cnt);
            }
            else{
                break;
            }

        }
    }
    return maxi;
}

//optimized approach o(n) time complexity and o(1) space complexity
int maxConsecutive(vector<int> &arr)
{
    int n = arr.size();
    int cnt = 0;
    int maxi = 0;
    for (int i = 0; i < n - 1; i++)
    {
       
        if (arr[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else
        {
            cnt=0;
        }
    }
    return maxi;
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
            if (!num.empty())
            {
                arr.push_back(stoi(num));
                num = "";
            }
        }
    }
    if (!num.empty())
    {
        arr.push_back(stoi(num));
    }

    int ans = maxConsecutive(arr);
    cout << ans;
    return 0;
}

/*


// JavaScript implementation of the same logic
function maxConsecBits(arr) {
    let maxCount = 0, count = 1;

    // Loop through the array starting from the second element
    for (let i = 1; i < arr.length; i++) {

        // If the current element is the same as the previous one
        // increment the count
        if (arr[i] === arr[i - 1]) {
            count++;
        }
        // If not equal, update maxCount if needed and reset count
        else {
            maxCount = Math.max(maxCount, count);
            count = 1;
        }
    }

    return Math.max(maxCount, count);
}

// Driver Code
let arr = [0, 1, 0, 1, 1, 1, 1];
console.log(maxConsecBits(arr));*/