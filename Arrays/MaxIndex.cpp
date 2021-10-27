#include <bits/stdc++.h>
using namespace std;
int maxIndex(int arr[], int n)
{
    int maxDiff;
    int i, j;
    int *Lmin = new int[sizeof(int) * n];
    int *Rmax = new int[(sizeof(int) * n)];
    Lmin[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        Lmin[i] = min(arr[i], Lmin[i - 1]);
    }
    Rmax[n - 1] = arr[n - 1];
    for (j = n - 2; j >= 0; j--)
    {
        Rmax[j] = max(arr[j], Rmax[j + 1]);
    }
    i = 0, j = 0, maxDiff = -1;

    while (j < n && i < n)
    {
        if (Lmin[i] <= Rmax[j])
        {
            maxDiff = max(maxDiff, j - i);
            j++;
        }
        else
            i++;
    }
    return maxDiff;
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
    cout << maxIndex(arr, n);
}