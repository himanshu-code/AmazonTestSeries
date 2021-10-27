#include <bits/stdc++.h>
using namespace std;
int strStr(string hayStack, string needle)
{
    int n = hayStack.length();
    int m = needle.length();
    if (n == 0 and m == 0)
        return 0;
    for (int i = 0; i <= n - m; i++)
    {
        int j;
        for (j = 0; j < m; j++)
        {
            if (hayStack[i + j] != needle[j])
                break;
        }
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}
int main()
{
    string hayStack, needle;
    cin >> hayStack;
    cin >> needle;
    cout << strStr(hayStack, needle);
}