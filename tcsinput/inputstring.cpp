#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; //'1 2 3 4 5 6 7 8'
    getline(cin, s);
    // case [1,2,3,4,5,6,7] s {1,2,3,4,5,6,7}
    // if(s.front()=='[' && s.back()==']'){
    //  s= s.substr(1,s.length()-2);
    //}

    stringstream ss(s); // '1' '2'
    // coma '1' ',' '2'
    vector<int> arr; // arr[] ->
    int num;
    // coma string temop;
    while (ss >> num) // space  // coma seprated (getline(ss,temp, ','));
                      // space  seprated (getline(ss,temp, ' '))
    {
        // int num = stoi(temp);
        arr.push_back(num);
    }

    for (int i = 0; i < arr.size(); i++)
    { 
        cout << arr[i] << " ";
    }

    return 0;
}



/*

int man(0[
int n;
cin>>n;

cin.ignore();
string s;
getline(cin,s);

cout<<n<< " " <<s<,endl;
return 0;
])*/