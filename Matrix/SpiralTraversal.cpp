#include <bits/stdc++.h>
using namespace std;
vector<int> spiral(vector<vector<int>> matrix, int r, int c)
{
    int sr = 0, sc = 0, er = r, ec = c;
    vector<int> v;
    while (sr < er && sc < ec)
    {
        for (int j = sc; j < ec; j++)
        {
            v.push_back(matrix[sr][j]);
        }
        sr++;
        for (int i = sr; i < er; i++)
        {
            v.push_back(matrix[i][ec - 1]);
        }
        ec--;
        if (sr < er)
        {
            for (int i = ec; i >= sc; i--)
            {
                v.push_back(matrix[er - 1][i]);
            }
            er--;
        }
        if (sc < ec)
        {
            for (int i = er - 1; i >= sr; i--)
            {
                v.push_back(matrix[i][sc]);
            }
            sc++;
        }
    }
    return v;
}
int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> matrix(r, vector<int>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<int> ans = spiral(matrix, r, c);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}