#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int l, int h, int x)
{
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] <= x)
        {
            l = mid + 1;
        }
        else
            h = mid - 1;
    }
    return h + 1;
}
vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], int m, int n)
{
    vector<int> v;
    sort(arr2, arr2 + n);
    for (int i = 0; i < m; i++)
    {
        int index = binarySearch(arr2, 0, n - 1, arr1[i]);
        v.push_back(index);
    }
    return v;
}
int main()
{
    int n, m;
    cin >> m >> n;
    int *arr1 = new int[m];
    int *arr2 = new int[n];
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }
    vector<int> ans = countEleLessThanOrEqual(arr1, arr2, m, n);
    for (auto x : ans)
        cout << x << " ";
}