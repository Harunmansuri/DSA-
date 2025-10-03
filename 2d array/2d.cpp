#include<bits/stdc++.h>

using namespace std;


bool arrSearch(int arr[][3], int target,int n,int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]== target){
                return 1;
            }
        }
    }
    return 0;

}
int main(){

    int arr[3][3]; //declaration

    
   // int arr[3][4] = {1,2,3,4,5,6,7,8,9,0,1,1};
   //taking row wise input
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cin>>arr[row][col];
        }
    }



   //taking col wise input
   /* for(int col=0;col<4;col++){
        for(int row=0;row<3;row++){
            cin>>arr[row][col];
        }
    }
        */

    //print
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            cout<<arr[row][col]<<" ";
        }
    }
    cout<<endl;
    cout<<"enter the element to be searched:-";
    int key;
    cin>>key;

    if(arrSearch(arr,key,3,3)){
        cout<<"element found"<<endl;
    }
    else{
        cout<<"elemet not found" <<endl;
    }
    return 0;
}