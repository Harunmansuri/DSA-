#include <bits/stdc++.h>
using namespace std;

int reverse(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return 0;
    }

    swap(nums[start], nums[end]);
    return reverse(nums, start + 1, end - 1);
}

int reverseArray(vector<int> &nums, int i){
    if(i >= nums.size()/2){
        return 0;
    }
    swap(nums[i], nums[nums.size()-1-i]);
    return reverseArray(nums, i+1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    int start = 0;
    int end = nums.size() - 1;
    reverse(nums, start, end);
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++)
    {
        cout << nums[i] << " ";
    }
}