#include <bits/stdc++.h>
using namespace std;

/*
    ===============================
        VECTOR CONCEPT COMPLETE
    ===============================

    1. Pass by Value
    2. Pass by Reference
    3. Returning Vector
    4. Modifying Vector
*/

//////////////////////////////////////////////////////////////
// 1️⃣ PASS BY VALUE  (Copy banti hai)
//////////////////////////////////////////////////////////////
void passByValue(vector<int> v)
{
    // Yaha v ki copy bani hai
    v.push_back(100);   // Sirf copy me add hoga

    cout << "Inside passByValue(): ";
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

//////////////////////////////////////////////////////////////
// 2️⃣ PASS BY REFERENCE  (Original modify hota hai)
//////////////////////////////////////////////////////////////
void passByReference(vector<int> &v)
{
    // Yaha original vector use ho raha hai
    v.push_back(200);   // Original me add hoga

    cout << "Inside passByReference(): ";
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

//////////////////////////////////////////////////////////////
// 3️⃣ RETURNING VECTOR
//////////////////////////////////////////////////////////////
vector<int> createVector()
{
    vector<int> temp;

    temp.push_back(10);
    temp.push_back(20);
    temp.push_back(30);

    return temp;   // Vector return ho raha hai
}

//////////////////////////////////////////////////////////////
// 4️⃣ VECTOR MODIFY & RETURN
//////////////////////////////////////////////////////////////
vector<int> addElement(vector<int> &v)
{
    v.push_back(500);   // Original modify

    return v;   // Modified vector return
}

//////////////////////////////////////////////////////////////
// MAIN FUNCTION
//////////////////////////////////////////////////////////////
int main()
{
    vector<int> arr;

    // Initial elements
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);

    cout << "Original vector: ";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    /////////////////////////////////////////////
    // Pass By Value
    /////////////////////////////////////////////
    passByValue(arr);

    cout << "After passByValue(): ";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    // Notice: 100 add nahi hua (copy thi)

    /////////////////////////////////////////////
    // Pass By Reference
    /////////////////////////////////////////////
    passByReference(arr);

    cout << "After passByReference(): ";
    for(int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
    // Notice: 200 add ho gaya (original modify hua)

    /////////////////////////////////////////////
    // Returning Vector
    /////////////////////////////////////////////
    vector<int> newVector = createVector();

    cout << "Returned vector: ";
    for(int i = 0; i < newVector.size(); i++)
        cout << newVector[i] << " ";
    cout << endl;

    /////////////////////////////////////////////
    // Modify and Return
    /////////////////////////////////////////////
    vector<int> modified = addElement(arr);

    cout << "After addElement(): ";
    for(int i = 0; i < modified.size(); i++)
        cout << modified[i] << " ";
    cout << endl;

    return 0;
}
