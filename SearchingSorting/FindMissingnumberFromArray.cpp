#include <bits/stdc++.h>
using namespace std;
int missingNumber2(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        while (arr[i] >= 1 && arr[i] <= n && arr[i] != arr[arr[i] - 1])
        {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != i + 1)
        {
            return i + 1;
        }
    }
    return n + 1;
}
int missingNumber(int arr[], int n)
{
    // Your code here
    bool present[n + 1] = {false};

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > 0 && arr[i] <= n)
        {
            present[arr[i]] = true;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!present[i])
            return i;
    }
    return n + 1;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << missingNumber2(arr, n) << endl;
    cout << missingNumber(arr, n);
}