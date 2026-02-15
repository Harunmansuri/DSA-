#include<bits/stdc++.h>
using namespace std;

void sort012(vector<int>& arr, int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1) {
            mid++;
        }
        else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort012(arr, n);   // 👈 function call

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}


/*
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int cnt0=0;
    int cnt1=0;
    int cnt2=0;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
               cnt0++;
        }
        else if(arr[i]==1){
            cnt1++;
        }
        else{
            cnt2++;
        }
    }

  
    for(int i=0; i<cnt0; i++){
           arr[i]=0;
    }
    
    for(int i=cnt0; i<cnt0+cnt1; i++){
           arr[i]=1;
    }
      for(int i=cnt0+cnt1; i<n; i++){
           arr[i]=2;
    }
    
    for(int i=0; i<n; i++){
        cout<<arr[i];
        cout<<endl;
    }
    

}
*/