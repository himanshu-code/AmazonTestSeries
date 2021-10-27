#include <bits/stdc++.h>
using namespace std;
vector<int> matrixDiagonal(vector<vector<int>> &mat)
{
    vector<int> v;
    int n = mat.size();
    int m = mat[0].size();
    int i = 0, j = 0;
    bool isUp = true;
    for (int k = 0; k < n * m;)
    {
        if (isUp)
        {
            for (; i >= 0 && j < m; j++, i--)
            {
                v.push_back(mat[i][j]);
                k++;
            }
            if (i < 0 && j <= m - 1)
                i = 0;
            if (j == m)
                i = i + 2, j--;
        }
        else
        {
            for (; j >= 0 && i < n; i++, j--)
            {
                v.push_back(mat[i][j]);
                k++;
            }
            if (j < 0 && i <= n - 1)
                j = 0;
            if (i == n)
                j = j + 2, i--;
        }
        isUp = !isUp;
    }
    return v;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    vector<int> ans = matrixDiagonal(mat);
    for (int x : ans)
        cout << x << " ";
}