#include <bits/stdc++.h>
using namespace std;
void rearrange(vector<int> &arr, int n)
{
    vector<int> pos, neg;

    // Separate positive and negative elements
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            neg.push_back(arr[i]);
        else
            pos.push_back(arr[i]);
    }

    int pSize = pos.size();
    int nSize = neg.size();

    // If positives are more
    if (pSize > nSize)
    {
        for (int i = 0; i < nSize; i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }
        //equal neg + postive tak ho gya hai

        int index = 2 * nSize;
        for (int i = nSize; i < pSize; i++)
        {
            arr[index++] = pos[i];
        }
    }
    else
    {
        for (int i = 0; i < pSize; i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        int index = 2 * pSize;
        for (int i = pSize; i < nSize; i++)
        {
            arr[index++] = neg[i];
        }
    }
}


int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    rearrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

/*
    vector<int> rearrange(vector<int> &arr, int n) {
    vector<int> ans(n, 0);

    int positive = 0;   // even index
    int negative = 1;   // odd index

    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            ans[positive] = arr[i];
            positive += 2;
        } else {
            ans[negative] = arr[i];
            negative += 2;
        }
    }

    return ans;
}

*/