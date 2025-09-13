#include <iostream>
using namespace std;

int search(int arr[], int key, int size)

{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12};
    int key;
    cin >> key;
    int linear = search(arr, key, 10);
    if (linear)
    {
        cout << "key is present " << endl;
    }
    else
    {
        cout << "key is absent" << endl;
    }
    return 0;
}