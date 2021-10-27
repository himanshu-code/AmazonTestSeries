#include <bits/stdc++.h>
using namespace std;
int longestUniqueString(string str)
{
    int n = str.size();
    int res = 0;
    vector<int> lastIndex(256, -1);
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, lastIndex[str[j]] + 1);
        res = max(res, j - i + 1);
        lastIndex[str[j]] = j;
    }
    return res;
}
int main()
{
    string str;
    cin >> str;
    cout << longestUniqueString(str);
}