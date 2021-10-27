#include <bits/stdc++.h>
using namespace std;
int equilibriumPoint(long long a[], int n)
{

    // Your code here
    int lsum = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum -= a[i];
        if (lsum == sum)
        {
            return i + 1;
        }
        lsum += a[i];
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << equilibriumPoint(arr, n);
}