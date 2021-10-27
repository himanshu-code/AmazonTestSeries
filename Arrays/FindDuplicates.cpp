#include <bits/stdc++.h>
using namespace std;
vector<int> duplicates(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int index = arr[i] % n;
        arr[index] += n;
    }
    bool flag = false;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] / n) > 1)
        {
            ans.push_back(i);
            flag = true;
        }
    }
    if (!flag)
        ans.push_back(-1);
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
    vector<int> ans = duplicates(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
