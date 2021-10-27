#include <bits/stdc++.h>
#include <vector>
using namespace std;
int MaxProfit(int arr[], int n)
{
    vector<int> dp(n + 1);

    dp[n] = 0;
    dp[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        dp[i] = max(arr[i] + dp[i + 2], dp[i + 1]);
    }
    return dp[0];
}
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << MaxProfit(arr, n);
}