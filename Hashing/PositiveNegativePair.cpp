#include <bits/stdc++.h>
using namespace std;
vector<int> PosNegPair(int arr[], int n)
{
    vector<int> v, ans;
    map<int, int> cnt;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            v.push_back(arr[i]);
        else
            cnt[arr[i]]++;
    }
    sort(v.begin(), v.end());
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (cnt[abs(v[i])] > 0)
        {
            ans.push_back(v[i]);
            ans.push_back(abs(v[i]));
            cnt[abs(v[i])] -= 1;
        }
    }
    return ans;
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
    vector<int> ans = PosNegPair(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}