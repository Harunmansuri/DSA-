#include <bits/stdc++.h>
using namespace std;

int main() {

    // -------------------------------
    // 1️⃣ Single Word Input
    // -------------------------------
    // Input Example:
    // hello

    string singleWord;
    cin >> singleWord;  
    // cin stops reading at space

    cout << "Single Word: " << singleWord << endl;


    // -----------------------------------------
    // Important: Clear newline from buffer
    // -----------------------------------------
    // After cin >> something,
    // newline (\n) remains in buffer.
    // So we remove it before using getline.
    cin.ignore();


    // -------------------------------
    // 2️⃣ Full Line Input (Sentence)
    // -------------------------------
    // Input Example:
    // hello world how are you

    string fullLine;
    getline(cin, fullLine);  
    // getline reads full line including spaces

    cout << "Full Line: " << fullLine << endl;


    // -------------------------------
    // 3️⃣ Number + String Input
    // -------------------------------
    // Input Example:
    // 5
    // coding is fun

    int number;
    cin >> number;

    cin.ignore();  // remove leftover newline

    string lineAfterNumber;
    getline(cin, lineAfterNumber);

    cout << "Number: " << number << endl;
    cout << "Line After Number: " << lineAfterNumber << endl;


    return 0;
}