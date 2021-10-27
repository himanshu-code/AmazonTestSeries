#include <bits/stdc++.h>
using namespace std;
int maxLen(int arr[], int n)
{
    unordered_map<int, int> m;
    int sum = 0;
    int max_len = 0;
    int end_index = -1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = (arr[i] == 0) ? -1 : 1;
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            max_len = i + 1;
            end_index = i;
        }
        if (m.find(sum) != m.end())
        {
            if (max_len < i - m[sum])
            {
                max_len = i - m[sum];
                end_index = i;
            }
        }
        else
            m[sum] = i;
    }
    return max_len;
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
    cout << maxLen(arr, n);
}