#include <bits/stdc++.h>
using namespace std;
void rearrange(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] += (arr[arr[i]] % n) * n;
    for (int i = 0; i < n; i++)
        arr[i] = arr[i] / n;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    rearrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}