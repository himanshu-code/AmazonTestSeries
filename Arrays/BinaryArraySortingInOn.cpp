#include <bits/stdc++.h>
using namespace std;
void BinarySort(int arr[], int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 1)
        {
            j++;
            swap(arr[i], arr[j]);
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
    BinarySort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}