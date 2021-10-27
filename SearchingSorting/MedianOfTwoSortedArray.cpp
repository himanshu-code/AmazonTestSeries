#include <bits/stdc++.h>
using namespace std;
double medianOfArrays(vector<int> &a, vector<int> &b)
{
    double answer;
    int m = a.size();
    int n = b.size();
    int size = ((m + n) / 2) + 1;
    vector<int> temp(size);
    for (int i = 0, j = 0, k = 0; i < size; i++)
    {
        if (k > n - 1)
        {
            temp[i] = a[j];
            j++;
        }
        else if (j > m - 1)
        {
            temp[i] = b[k];
            k++;
        }
        else if (a[j] <= b[k])
        {
            temp[i] = a[j];
            j++;
        }
        else if (a[j] > b[k])
        {
            temp[i] = b[k];
            k++;
        }
    }
    if ((m + n) % 2 == 0)
    {
        answer = (((double)(temp[size - 1] + temp[size - 2])) / 2);
    }
    else
        answer = temp[size - 1];

    return answer;
}
int main()
{
    int n, m;
    cin >> m >> n;
    vector<int> a(m), b(n);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << medianOfArrays(a, b);
}