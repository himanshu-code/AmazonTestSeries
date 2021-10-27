#include <bits/stdc++.h>
using namespace std;
int circularSubArraySum(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int curr_max = arr[0], max_so_far = arr[0], curr_min = arr[0], min_so_far = arr[0];
    for (int i = 1; i < n; i++)
    {
        curr_max = max(curr_max + arr[i], arr[i]);
        max_so_far = max(max_so_far, curr_max);

        curr_min = min(curr_min + arr[i], arr[i]);
        min_so_far = min(min_so_far, curr_min);
    }
    if (min_so_far == sum)
        return max_so_far;

    return max(max_so_far, sum - min_so_far);
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
    cout << circularSubArraySum(arr, n);
}