#include <bits/stdc++.h>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void waveSort(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if (i > 0 and arr[i - 1] > arr[i])
        {
            swap(&arr[i], &arr[i - 1]);
        }
        if (i < n - 1 and arr[i] < arr[i + 1])
        {
            swap(&arr[i], &arr[i + 1]);
        }
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
    waveSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
