#include <bits/stdc++.h>
using namespace std;
int strstr(string s, string x)
{
    int n = s.length();
    int m = x.length();
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (s[i + j] != x[j])
                break;
        }
        if (j == m)
            return i;
    }
    return -1;
}
int main()
{
    string s, x;
    cin >> s;
    cin >> x;
    cout << strstr(s, x);
}