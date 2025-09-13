#include <iostream>
using namespace std;

/*bool ispresent(int arr[3][4], int target, int row, int col)
{
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (arr[row][col] == target)
            {
                return 1;
            }
        }
    }
    return 0;
}*/

/*void printSumrow(int arr[3][4], int row, int col)
{

    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for(int col =0; col < 4; col++){
            sum += arr[row][col];
        }
        cout << "sum is " << sum <<endl;
    }
    cout << endl;
}*/

/*void printSumcol(int arr[3][4], int row, int col)
{

    for (int col = 0; col< 4; col++)
    {
        int sum = 0;
        for(int row =0; row < 3; row++){
            sum += arr[row][col];
        }
        cout << "sum is " << sum <<endl;
    }
    cout << endl;
}*/
int largestRowSum(int arr[3][4], int row, int col)
{
    int maxi = -1;
    int rowindex = -1;
    for (int row = 0; row < 3; row++)
    {
        int sum = 0;
        for (int col = 0; col < 4; col++)
        {
            sum += arr[row][col];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowindex = row;
        }
    }

    cout << "the maximum sum is " << maxi << endl;
    return rowindex;
}
int main()
{

    // create 2d array
    int arr[3][4];
    // int arr[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};
    // row wise manually
    // int arr[3][4] = {{1,2,3,4} , {5,6,7,8} , {9,10,11,12} };

    cout << "enter the elemets row wise " << endl;

    // taking input row wise
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cin >> arr[row][col];
        }
    }

    /*//taking input colwise
        for(int col=0; col<4; col++){
         for(int row=0; row<3; row++){
             cin >> arr[row][col];

         }
     }
     */

    // print matrix
    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }

    /* cout << "enter the elements to serch for " << endl;
     int target;
     cin >> target;
     if (ispresent(arr, target, 3, 4))
     {
         cout << "element found" << en dl;
     }
     else
     {
         cout << "element not found " << endl;
     }
     return 0;*/
    // printSumrow(arr,3,4);
   //  printSumcol(arr, 3, 4);
   int ansindex = largestRowSum(arr,3,4);
   cout << "max row is at index " <<ansindex <<endl; 
    return 0;
}