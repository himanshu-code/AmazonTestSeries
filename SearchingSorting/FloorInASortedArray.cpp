#include <bits/stdc++.h>
using namespace std;
int floorSearch(long long int arr[], int l, int h, int K)
{
    if (l > h)
        return -1;
    if (K >= arr[h])
    {
        return h;
    }
    int mid = (l + h) / 2;
    if (mid >= 0 && arr[mid - 1] <= K && K < arr[mid])
    {
        return mid - 1;
    }
    if (K < arr[mid])
    {
        return floorSearch(arr, l, mid - 1, K);
    }
    return floorSearch(arr, mid + 1, h, K);
}
int findFloor(long long int arr[], int n, long long int K)
{
    return floorSearch(arr, 0, n - 1, K);
}
int main()
{
    int n;
    long long int k;
    cin >> n >> k;
    long long int *arr = new long long int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << findFloor(arr, n, k);
}