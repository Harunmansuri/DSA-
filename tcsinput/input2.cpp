#include <bits/stdc++.h>
using namespace std;

int main() {

    string line;

    // Read complete line input (example: 1 2 3 4 5)
    getline(cin, line);

    // Create stringstream object using input line
    stringstream ss(line);

    vector<int> arr;   // Vector to store extracted integers
    int num;

    // Extract integers one by one from stringstream
    while(ss >> num) {
        arr.push_back(num);   // Store in vector
    }

    // Print the elements
    for(int x : arr) {
        cout << x << " ";
    }

    return 0;
}