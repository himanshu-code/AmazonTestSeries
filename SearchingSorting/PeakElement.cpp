#include <bits/stdc++.h>
using namespace std;
int peakElement(int arr[], int n)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (low + high) / 2;
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        {
            return mid;
        }
        else if (mid > 0 && arr[mid - 1] > arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
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
    cout << arr[peakElement(arr, n)];
}