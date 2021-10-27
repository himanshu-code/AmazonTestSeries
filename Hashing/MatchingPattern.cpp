#include <bits/stdc++.h>
using namespace std;
bool check(string word, string pattern)
{
    if (pattern.length() != word.length())
    {
        return false;
    }
    char ch[128] = {0};
    int len = word.length();
    for (int i = 0; i < len; i++)
    {
        if (ch[pattern[i]] == 0)
            ch[pattern[i]] = word[i];
        else if (ch[pattern[i]] != word[i])
            return false;
    }
    return true;
}
vector<string> findMatchedWords(vector<string> dict, string pattern)
{
    vector<string> v;
    for (auto x : dict)
    {
        if (check(x, pattern))
            v.push_back(x);
    }
    return v;
}
int main()
{
    int n;
    cin >> n;
    vector<string> dict(n);
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    string pattern;
    cin >> pattern;
    vector<string> ans = findMatchedWords(dict, pattern);
    for (auto x : ans)
        cout << x << " ";
}