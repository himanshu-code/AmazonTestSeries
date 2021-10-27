#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
int findK(vector<vector<int>> arr, int n, int m, int k)
{
    int top = 0, left = 0, right = m - 1, bottom = n - 1, dir = 0, count = 0;
    vector<int> v;
    while (top <= bottom and left <= right)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
            {
                v.push_back(arr[top][i]);
            }
            top++;
            dir = 1;
        }
        if (dir == 1)
        {
            for (int i = top; i <= bottom; i++)
            {
                v.push_back(arr[i][right]);
            }
            right--;
            dir = 2;
        }
        if (dir == 2)
        {
            for (int i = right; i >= left; i--)
            {
                v.push_back(arr[bottom][i]);
            }
            bottom--;
            dir = 3;
        }
        if (dir == 3)
        {
            for (int i = bottom; i >= top; i--)
            {
                v.push_back(arr[i][left]);
            }
            left++;
            dir = 0;
        }
    }
    return v[k - 1];
}
int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << findK(arr, n, m, k);
    return 0;
}