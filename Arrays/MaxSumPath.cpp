#include <bits/stdc++.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}
int getMaxSumPath(int A[], int B[], int m, int n)
{
    int i = 0, j = 0;
    int result = 0, sum1 = 0;
    int sum2 = 0;
    while (i < m && j < n)
    {
        if (A[i] < B[j])
            sum1 += A[i++];
        else if (A[i] > B[j])
            sum2 += B[j++];
        else
        {
            result += max(sum1, sum2) + A[i];
            sum1 = 0;
            sum2 = 0;
            i++;
            j++;
        }
    }
    while (i < m)
        sum1 += A[i++];
    while (j < n)
        sum2 += B[j++];

    result += max(sum1, sum2);
    return result;
}
using namespace std;
int main()
{
    int n, m;
    cin >> m >> n;
    int A[10000], B[10000];
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    cout << getMaxSumPath(A, B, m, n);
}