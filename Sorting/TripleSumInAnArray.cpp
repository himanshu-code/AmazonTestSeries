#include <bits/stdc++.h>
using namespace std;
bool find3Numbers(int A[], int n, int X)
{
    //Your Code Here
    sort(A, A + n);
    for (int i = 0; i < n; i++)
    {
        int l = i + 1;
        int r = n - 1;
        while (l < r)
        {
            if (A[i] + A[l] + A[r] == X)
            {
                return true;
            }
            else if (A[i] + A[l] + A[r] < X)
                l++;
            else
                r--;
        }
    }
    return false;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int X;
    cin >> X;
    if (find3Numbers(arr, n, X))
        cout << 1;
    else
        cout << 0;
}