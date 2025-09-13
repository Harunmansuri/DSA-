#include<iostream>
using namespace std;
   
int checkarray(int arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == 5)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    int arr[] = {1, 3, 1, 5, 7};
    int ans = checkarray(arr, 5);
}