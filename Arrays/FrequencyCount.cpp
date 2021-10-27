#include <bits/stdc++.h>
using namespace std;
void frequencyCount(int arr[], int n, int P)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] -= 1;
    }
    sort(arr, arr + n);
    int ind = n;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= n)
        {
            if (ind == n)
                ind = i;
            arr[i] = 0;
        }
    }
    for (int i = 0; i < ind; i++)
        arr[arr[i] % n] = arr[arr[i] % n] + n;

    for (int i = 0; i < n; i++)
        arr[i] = arr[i] / n;
}
int main()
{
    int n, P;
    cin >> n >> P;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    frequencyCount(arr, n, P);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}