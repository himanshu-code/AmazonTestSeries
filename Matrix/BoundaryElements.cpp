#include <bits/stdc++.h>
using namespace std;
vector<int> BoundaryElement(vector<vector<int>> &matrix)
{
    vector<int> v;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (i == 0 or j == 0 or i == matrix.size() - 1 or j == matrix[0].size() - 1)
            {
                v.push_back(matrix[i][j]);
            }
        }
    }
    return v;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    vector<int> ans = BoundaryElement(matrix);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}