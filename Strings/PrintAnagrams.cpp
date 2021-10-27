#include <bits/stdc++.h>
using namespace std;
vector<vector<string>> Anagrams(vector<string> &s_list)
{
    unordered_map<string, vector<string>> m;
    vector<vector<string>> v;
    for (int i = 0; i < s_list.size(); i++)
    {
        string word = s_list[i];
        sort(word.begin(), word.end());
        m[word].push_back(s_list[i]);
    }
    for (auto i : m)
    {
        v.push_back(i.second);
    }
    return v;
}
int main()
{

    int n = 0;
    cin >> n;
    vector<string> s_list(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s_list[i];
    }
    vector<vector<string>> ans = Anagrams(s_list);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}