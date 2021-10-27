#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> fourSum(vector<int> arr, int k)
{
    if (arr.size() < 4)
        return {};

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 3; ++i)
    {
        if (arr[i] > 0 && arr[i] > k)
            break;

        if (i > 0 && arr[i] > k)
            continue;
        for (int j = i + 1; j < arr.size() - 2; ++j)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;

            int left = j + 1;
            int right = arr.size() - 1;
            while (left < right)
            {
                int old_l = left;
                int old_r = right;
                int sum = arr[i] + arr[j] + arr[left] + arr[right];
                if (sum == k)
                {
                    ans.push_back({arr[i], arr[j], arr[left], arr[right]});
                    while (left < right && arr[left] == arr[old_l])
                        left++;
                    while (left < right && arr[right] == arr[old_r])
                        right--;
                }
                else if (sum > k)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
    }
    return ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> ans = fourSum(arr, k);
    for (auto &v : ans)
    {
        for (int &u : v)
        {
            cout << u << " ";
        }
        cout << "$";
    }
}