#include<bits/stdc++.h>


using namespace std;

// function to reverse an array
void reverseArray(int arr[], int n)
{

    // Initialize left to the beginning and right to the end
    int left = 0, right = n - 1;

    // Iterate till left is less than right
    while (left < right)
    {

        // Swap the elements at left and right position
        swap(arr[left], arr[right]);

        // Increment the left pointer
        left++;

        // Decrement the right pointer
        right--;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[6] = {1, 4, 3, 2, 6, 5};

    reverseArray(arr, 6);
    printArray(arr, 6);

    return 0;
}