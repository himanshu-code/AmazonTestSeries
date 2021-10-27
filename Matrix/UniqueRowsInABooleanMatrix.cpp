#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
vector<vector<int>> uniqueRow(vector<vector<int>> &M, int row, int col)
{
    set<string> st;
    vector<vector<int>> vec;
    for (int i = 0; i < row; i++)
    {
        string curr;
        for (int j = 0; j < col; j++)
        {
            curr += '0' + M[i][j];
        }
        st.insert(curr);
    }
    for (int i = 0; i < row; i++)
    {
        string curr;
        for (int j = 0; j < col; j++)
        {
            curr += '0' + M[i][j];
        }
        if (st.find(curr) != st.end())
        {
            st.erase(curr);
            vector<int> demo;
            for (int j = 0; j < col; j++)
            {
                demo.push_back(M[i][j]);
            }
            vec.push_back(demo);
        }
    }
    return vec;
}
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<int>> M(row, vector<int>(col));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cin >> M[i][j];
        }
    }
    vector<vector<int>> vec = uniqueRow(M, row, col);
    for (int i = 0; i < vec.size(); i++)
    {
        for (int x : vec[i])
            cout << x << " ";
        cout << "$";
    }
    return 0;
}