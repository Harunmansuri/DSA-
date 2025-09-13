#include<bits/stdc++.h>

using namespace std;

int getmax(int num[] , int n){
    int maxe = 0;
    for(int i =0; i<n; i++){
        if(num[i] > maxe)
        {
            maxe = num[i];
        }
    }
    return maxe;


}
int getmin(int num[] , int n){
    int mine = 100000000;
    for(int i =0; i<n; i++){
        if(num[i] < mine)
        {
            mine = num[i];
        }
    }
    return mine;


}
int main(){
    //int size;
    //cin >> size;
    //int num[100];
    int num[10] = {-12, 12,24,3,4,67,90,32,45,11};
    // taking input in array
   // for(int i=0; i<size; i++){
   //     cin >> num[i];
  //  }
    cout << "maximum value is " << getmax(num, 10) << endl;
    cout << "mininum value is " << getmin(num, 10) << endl;



}