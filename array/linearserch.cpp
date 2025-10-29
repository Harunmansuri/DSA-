#include <iostream>
using namespace std;

// ✅ Function to perform Binary Search (efficient method)
int search(int arr[], int key, int size)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        // Calculate the middle index
        int mid = start + (end - start) / 2;

        // If the element at mid is the key
        if (arr[mid] == key)
        {
            return mid; // Return index of found key
        }

        // If key is smaller, move to the left half
        if (arr[mid] > key)
        {
            end = mid - 1;
        }
        // If key is larger, move to the right half
        else
        {
            start = mid + 1;
        }
    }

    // If key is not found
    return -1;
}

/* --------------------------------------------------------
   🧩 Alternative version 1: Linear Search (returns index)
   --------------------------------------------------------
int search(int arr[], int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return i;  // Return index where key is found
        }
    }
    return -1; // Key not found
}
*/

/* --------------------------------------------------------
   🧩 Alternative version 2: Linear Search (returns boolean)
   --------------------------------------------------------
int search(int arr[], int key, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;  // Key found
        }
    }
    return 0; // Key not found
}
*/

int main()
{
    // Sorted array for Binary Search
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12};

    int key;
    cout << "Enter the key to search: ";
    cin >> key;

    // Call the search function
    int index = search(arr, key, 10);

    // Print the result
    if (index != -1)
    {
        cout << "Key is present at index " << index << endl;
    }
    else
    {
        cout << "Key is absent" << endl;
    }

    return 0;
}
