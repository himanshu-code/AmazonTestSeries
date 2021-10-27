#include <bits/stdc++.h>
using namespace std;
int matSearch(vector<vector<int>> &matrix, int n, int m, int x)
{
    int smallest = matrix[0][0], largest = matrix[n - 1][m - 1];
    if (x < smallest || x > largest)
    {
        return 0;
    }
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == x)
            return 1;

        if (matrix[i][j] > x)
            j--;
        else
            i++;
    }
    return 0;
}
int main()
{
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    cout << matSearch(matrix, n, m, x);
}