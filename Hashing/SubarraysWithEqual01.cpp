#include <bits/stdc++.h>
using namespace std;
long long int countSubarrayWithEqual01(int arr[], int n)
{
    unordered_map<int, int> m;
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += (arr[i] == 0) ? -1 : arr[i];
        m[curr_sum]++;
    }
    int count = 0;
    for (auto itr = m.begin(); itr != m.end(); itr++)
    {
        if (itr->second > 1)
            count += ((itr->second * (itr->second - 1)) / 2);
    }
    if (m.find(0) != m.end())
        count += m[0];
    return count;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << countSubarrayWithEqual01(arr, n);
}