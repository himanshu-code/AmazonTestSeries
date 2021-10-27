#include <bits/stdc++.h>
using namespace std;
bool hasPair(int arr[], int n, int x)
{
    unordered_set<int> m;
    for (int i = 0; i < n; i++)
    {
        int temp = x - arr[i];
        if (m.find(temp) != m.end())
        {
            return true;
        }
        m.insert(arr[i]);
    }
    return false;
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
    int x;
    cin >> x;
    if (hasPair(arr, n, x))
        cout << "Yes";
    else
        cout << "No";
}