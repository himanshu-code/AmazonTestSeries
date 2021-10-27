#include <bits/stdc++.h>
using namespace std;
int findTransitionPoint(int arr[], int n)
{
    int l = 0, h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (arr[mid] == 0)
        {
            l = mid + 1;
        }
        else if (arr[mid] == 1)
        {
            if (mid == 0 || (mid > 0 && arr[mid - 1] == 0))
            {
                return mid;
            }
            h = mid - 1;
        }
    }
    return -1;
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
    int ans = findTransitionPoint(arr, n);
    if (ans >= 0)
        cout << ans;
    else
        cout << "No Transition Point";
}