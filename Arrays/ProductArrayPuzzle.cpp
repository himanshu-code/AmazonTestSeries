#include <bits/stdc++.h>
using namespace std;
vector<long long int> productArray(long long int arr[], int n)
{
    long long int product = 1;
    long long int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            flag++;
        else
            product *= arr[i];
    }
    vector<long long int> v(n);
    for (int i = 0; i < n; i++)
    {
        if (flag > 1)
        {
            v[i] = 0;
        }
        else if (flag == 0)
            v[i] = product / arr[i];
        else if (flag == 1 and arr[i] != 0)
        {
            v[i] == 0;
        }
        else
            v[i] = product;
    }
    return v;
}
int main()
{
    int n;
    cin >> n;
    long long int *arr = new long long int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<long long int> ans = productArray(arr, n);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}