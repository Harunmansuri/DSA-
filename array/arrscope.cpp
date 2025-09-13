#include <iostream>
using namespace std;

void updatearr(int num[], int n)
{
    cout << "inside the function" << endl;
    // updarting the first element 
    num[0] = 120;


    //printing the arr
    for (int i = 0; i < 4; i++)
    {
        cout << num[i]<<endl;
    }
    cout <<"going back to main function"<<endl;
}

int main()
{
    int num[4] = {1, 2, 3, 4};
    updatearr(num,4);

    cout <<"printing the main array" <<endl;
    
    for (int i = 0; i < 4; i++)
    {
        cout << num[i]<<endl;
    }
    
}