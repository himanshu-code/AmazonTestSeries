#include <bits/stdc++.h>
using namespace std;
vector<int> find3numbers(vector<int> arr, int n)
{
    int max = n - 1;
    int min = 0;
    int i;
    int *smaller = new int[n];
    smaller[0] = -1;
    for (i = 0; i < n; i++)
    {
        if (arr[i] <= arr[min])
        {
            min = i;
            smaller[i] = -1;
        }
        else
        {
            smaller[i] = min;
        }
    }
    int *greater = new int[n];
    greater[n - 1] = -1;
    for (i = n - 2; i >= 0; i--)
    {
        if (arr[i] >= arr[max])
        {
            max = i;
            greater[i] = -1;
        }
        else
            greater[i] = max;
    }
    vector<int> r;
    for (int i = 0; i < n; i++)
    {
        if (smaller[i] != -1 and greater[i] != -1)
        {
            r.push_back(arr[smaller[i]]);
            r.push_back(arr[i]);
            r.push_back(arr[greater[i]]);
            return r;
        }
    }
    delete[] smaller;
    delete[] greater;
    return r;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> res = find3numbers(arr, n);
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}