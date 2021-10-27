#include <bits/stdc++.h>
using namespace std;
string smallestWindow(string str, string pattern)
{
    int m[256] = {0};
    int ans = INT_MAX;
    int start = 0, count = 0;
    for (int i = 0; i < pattern.length(); i++)
    {
        if (m[pattern[i]] == 0)
            count++;
        m[pattern[i]]++;
    }
    int i = 0, j = 0;
    while (j < str.length())
    {
        m[str[j]]--;
        if (m[str[j]] == 0)
            count--;
        if (count == 0)
        {
            while (count == 0)
            {
                if (ans > j - i + 1)
                {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                m[str[i]]++;
                if (m[str[i]] > 0)
                    count++;

                i++;
            }
        }
        j++;
    }
    if (ans != INT_MAX)
        return str.substr(start, ans);
    else
        return "-1";
}
int main()
{
    string str, pattern;
    cin >> str;
    cin >> pattern;
    cout << smallestWindow(str, pattern);
}