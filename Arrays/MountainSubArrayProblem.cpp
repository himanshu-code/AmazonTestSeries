#include <bits/stdc++.h>
using namespace std;
void preprocess(int arr[], int n, int left[], int right[])
{
    left[0] = 0;
    int lastincr = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
            lastincr = i;
        left[i] = lastincr;
    }
    right[n - 1] = n - 1;
    int firstdecr = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > arr[i + 1])
        {
            firstdecr = i;
        }
        right[i] = firstdecr;
    }
}
bool isSubArrayMountainForm(int left[], int right[], int l, int r)
{
    return (right[l] >= left[r]);
}
vector<bool> processQueries(int arr[], int n, vector<pair<int, int>> &queries, int q)
{
    int *left = new int[n];
    int *right = new int[n];
    preprocess(arr, n, left, right);
    vector<bool> v;
    for (int i = 0; i < q; i++)
    {
        v.push_back(isSubArrayMountainForm(left, right, queries[i].first, queries[i].second));
    }
    return v;
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
    int q;
    cin >> q;
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; i++)
    {
        cin >> queries[i].first >> queries[i].second;
    }
    vector<bool> ans = processQueries(arr, n, queries, q);
    for (bool u : ans)
    {
        cout << (u ? "Yes\n" : "No\n");
    }
}
