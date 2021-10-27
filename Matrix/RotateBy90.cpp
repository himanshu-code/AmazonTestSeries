#include <bits/stdc++.h>
using namespace std;
void rotateby90(int n, vector<vector<int>> &arr)
{
    for (int x = 0; x < n / 2; x++)
    {
        for (int y = x; y < n - x - 1; y++)
        {
            int temp = arr[x][y];
            arr[x][y] = arr[y][n - 1 - x];
            arr[y][n - 1 - x] = arr[n - 1 - x][n - 1 - y];
            arr[n - 1 - x][n - 1 - y] = arr[n - 1 - y][x];
            arr[n - 1 - y][x] = temp;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    rotateby90(n, arr);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}