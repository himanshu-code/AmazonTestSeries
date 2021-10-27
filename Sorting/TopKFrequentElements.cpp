#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &p, pair<int, int> &p1)
{
    if (p.second == p1.second)
        return p.first > p1.first;
    return p.second > p1.second;
}
vector<int> topK(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> v;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    vector<pair<int, int>> v2(m.begin(), m.end());
    sort(v2.begin(), v2.end(), cmp);
    for (auto &x : v2)
    {
        v.push_back(x.first);
        k--;
        if (k == 0)
            return v;
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
    int k;
    cin >> k;
    vector<int> ans = topK(arr, k);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}