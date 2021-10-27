#include <bits/stdc++.h>
int findExtra(int arr1[], int arr2[], int n)
{
    int index = n - 1;
    int left = 0, right = n - 2;
    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (arr1[mid] == arr2[mid])
        {
            left = mid + 1;
        }
        else
        {
            index = mid;
            right = mid - 1;
        }
    }
    return index;
}
using namespace std;
int main()
{
    int n;
    cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr2[i];
    }
    cout << findExtra(arr1, arr2, n);
}