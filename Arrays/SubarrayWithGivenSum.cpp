#include <bits/stdc++.h>
using namespace std;
vector<int> subarraySum(int arr[], int n, int sum)
{
    int csum = arr[0];
    int start = 0, i;
    vector<int> v;
    for (i = 1; i <= n; i++)
    {
        while (csum > sum && start < i - 1)
        {
            csum = csum - arr[start];
            start++;
        }
        if (csum == sum)
        {
            v.push_back(start + 1);
            v.push_back(i);
            break;
        }
        if (i < n)
            csum += arr[i];
    }
    if (v.size() == 0)
        v.push_back(-1);
    return v;
}
int main()
{
    int n, sum;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> sum;
    vector<int> ans = subarraySum(arr, n, sum);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}