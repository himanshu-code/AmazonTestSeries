#include <bits/stdc++.h>
using namespace std;
vector<int> SortA1ByA2(int arr1[], int n, int arr2[], int m)
{
    vector<int> v;
    map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[arr1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        while (map[arr2[i]] > 0)
        {
            v.push_back(arr2[i]);
            map[arr2[i]]--;
        }
    }
    for (auto it : map)
    {
        while (it.second > 0)
        {
            v.push_back(it.first);
            it.second--;
        }
    }
    return v;
}
int main()
{
    int n, m;
    cin >> n >> m;
    int *arr1 = new int[n];
    int *arr2 = new int[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    vector<int> ans = SortA1ByA2(arr1, n, arr2, m);
    for (auto x : ans)
        cout << x << " ";
}