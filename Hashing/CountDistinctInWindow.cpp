#include <bits/stdc++.h>
using namespace std;
vector<int> countDistinct(int arr[], int n, int k)
{
    unordered_map<int, int> m;
    vector<int> result;
    for (int i = 0; i < k; i++)
        m[arr[i]]++;
    result.push_back(m.size());

    for (int i = 1; i < n - k + 1; i++)
    {
        m[arr[i - 1]]--;
        if (m[arr[i - 1]] <= 0)
            m.erase(arr[i - 1]);
        m[arr[i + k - 1]]++;
        result.push_back(m.size());
    }
    return result;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = countDistinct(arr, n, k);
    for (auto x : ans)
        cout << x << " ";
}