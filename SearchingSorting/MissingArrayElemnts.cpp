#include <bits/stdc++.h>
using namespace std;
int MissingNumber(int arr[], int n)
{
    int total = (n * (n + 1)) / 2;
    for (int i = 0; i < n - 1; i++)
    {
        total -= arr[i];
    }
    return total;
}
int getMissingNumber(int arr[], int n)
{
    int x1 = arr[0];
    int x2 = 1;
    for (int i = 1; i < n - 1; i++)
    {
        x1 = x1 ^ arr[i];
    }
    for (int i = 2; i <= n; i++)
    {
        x2 = x2 ^ i;
    }
    return (x1 ^ x2);
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    cout << getMissingNumber(arr, n) << endl;
    cout << MissingNumber(arr, n);
}