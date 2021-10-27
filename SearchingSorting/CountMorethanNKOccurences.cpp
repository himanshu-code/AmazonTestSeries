#include <bits/stdc++.h>
using namespace std;
int countOccurence(int arr[], int n, int k)
{
    int d = n / k;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    int count = 0;
    for (auto x : m)
    {
        if (x.second > d)
            count++;
    }
    return count;
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
    int k;
    cin >> k;
    cout << countOccurence(arr, n, k);
}