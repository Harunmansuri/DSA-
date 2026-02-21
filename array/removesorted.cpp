#include <bits/stdc++.h>
using namespace std;

/*
   Function: removeDuplicate
   Purpose: Remove duplicates using set
   Returns: New size after removing duplicates
   Note: Overwrites original array
*/
int removeDuplicate(vector<int> &arr)
{

    set<int> st;

    // Insert all elements into set (duplicates automatically removed)
    for (int i = 0; i < arr.size(); i++)
    {
        st.insert(arr[i]);
    }

    int index = 0;

    // Copy unique elements back into original array
    for (int x : st)
    {
        arr[index] = x;
        index++;
    }

    return index; // Return new size
}

int main()
{

    // ----------- TCS Style Input -------------
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> arr;
    int num;

    while (ss >> num)
    {
        arr.push_back(num);
    }

    // Call function
    int newSize = removeDuplicate(arr);

    // Print updated array till newSize
    for (int i = 0; i < newSize; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*
    Time Complexity: O(n log n) due to set insertion
    Space Complexity: O(n) for the set storing unique elements

    Note: This approach does not maintain the original order of elements.
            If order needs to be preserved, a different method using an unordered_set can be used.
*/

/*

int remove(vector<int> & arr, int n)
{
    if(arr.size()==0) return 0;
   vector<int > temp;
  temp.push_back(arr[0]);
   for(int i=1; i<n; i++){
    if(arr[i] != arr[i-1]){
      temp.push_back(arr[i]);

    }

    //copy  unique eleemt to roignal afrray
    int index =0;
   for(auto x: temp){

      arr[index]=x;
      index++;
   }
      return index;

   }
}
int main() {

    // TCS Style Input using getline
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> arr;
    int num;

    while(ss >> num) {
        arr.push_back(num);
    }

    int newSize = removeDuplicateBetter(arr);

    for(int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
*/

/*
tc=o(n);
#include <bits/stdc++.h>
using namespace std;

/*
   Optimal Approach
   Two Pointer Technique
   Removes duplicates in-place
   Returns new size
*/
/*
int removeDuplicateOptimal(vector<int> &arr) {

    if(arr.size() == 0) return 0;

    int i = 0;  // Points to last unique element

    for(int j = 1; j < arr.size(); j++) {

        // If new unique element found
        if(arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    return i + 1;   // New size
}

int main() {

    // TCS Style Input
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<int> arr;
    int num;

    while(ss >> num) {
        arr.push_back(num);
    }

    int newSize = removeDuplicateOptimal(arr);

    for(int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}







*/