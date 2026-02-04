#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key)
{
    if (start > end)
    {
        return false;
    }

    int mid = start + (end - start) / 2;
    if (arr[mid] == key)
    {
        return true;
    }
    if (arr[mid] > key)
    {
       return binarySearch(arr, start, mid-1,key);
    }
    else{
       return binarySearch(arr,mid+1,end,key);
    }
}

int main()
{
    int n;
    cin >> n;
   
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
     int key;
    cin >> key;
    int start = 0;
    int end = n - 1;
    binarySearch(arr, start, end, key);
    if(binarySearch){
        cout<<"found";
    }
    else{
        cout<<"not found";
    }
}
