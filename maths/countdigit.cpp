#include <bits/stdc++.h>
using namespace std;

int countDigit(int n)
{
    // Base case
    if (n == 0)
        return 1;

    int count = 0;

    // Iterate till n has digits remaining
    while (n != 0)
    {

        // Remove rightmost digit
        n = n / 10;

        // Increment digit count by 1
        ++count;
    }
    return count;
}

int main()
{
    int n = 58964;
    cout << countDigit(n);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Recursively count the number of digits in the integer 'n'
int countDigit(int n)
{
    // Base case: if 'n' is a single digit
    if (n / 10 == 0)
        return 1;

    // Recursive case: strip one digit and count
    return 1 + countDigit(n / 10);
}

int main()
{
    int n = 58964;
    cout << countDigit(n); 
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int countDigit(int n)
{
    // Convert the integer to a string
    string num = to_string(n);

    // Return the length of the string (i.e., number of digits)
    return num.length();
}

int main()
{
    int n = 58964;
    cout << countDigit(n); 
    return 0;
}