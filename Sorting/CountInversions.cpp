#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll merge(long long int arr[], long long int left, long long int mid, long long int right)
{
    ll n1 = mid - left + 1;

    ll n2 = right - mid;

    ll a[n1], b[n2];

    for (ll i = 0; i < n1; i++)
    {
        a[i] = arr[left + i];
    }

    for (ll i = 0; i < n2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }
    ll i = 0, j = 0, k = left;

    ll in = 0;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
            arr[k++] = a[i++];

        else
        {
            arr[k++] = b[j++];
            in += (n1 - i);
        }
    }
    while (i < n1)
        arr[k++] = a[i++];

    while (j < n2)
        arr[k++] = b[j++];
    return in;
}
long long int mergeSort(long long int arr[], long long int left, long long int right)
{
    long long int mid, inv_count = 0;
    if (left >= right)
        return 0;

    mid = (right + left) / 2;
    inv_count += mergeSort(arr, left, mid);
    inv_count += mergeSort(arr, mid + 1, right);
    inv_count += merge(arr, left, mid, right);

    return inv_count;
}
long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here

    return mergeSort(arr, 0, N - 1);
}
int main()
{
    ll n;
    cin >> n;
    ll *arr = new ll[n];
    for (auto i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << inversionCount(arr, n);
}