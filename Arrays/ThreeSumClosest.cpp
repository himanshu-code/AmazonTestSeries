#include <bits/stdc++.h>
using namespace std;
int closestThreeSum(vector<int> arr, int target)
{
    int flag = 0, n = arr.size();
    int res;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n - 2; ++i)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (!flag)
            {
                res = sum;
                flag = 1;
            }
            if (abs(sum - target) < abs(res - target))
                res = sum;
            else if (abs(sum - target) == abs(res - target))
            {
                if (sum > res)
                    res = sum;
            }
            if (target > sum)
                j++;
            else
                k--;
        }
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << closestThreeSum(arr, target);
}