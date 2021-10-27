#include <bits/stdc++.h>
using namespace std;
void permute(string S, int start, int end, string current, vector<string> &result)
{
    if (start > end)
    {
        result.push_back(current);
        return;
    }
    current.push_back(S[start]);
    permute(S, start + 1, end, current, result);
    current.insert(current.length() - 1, 1, ' ');
    permute(S, start + 1, end, current, result);
}
vector<string> permutation(string S)
{
    vector<string> v;
    string current;
    current.push_back(S[0]);
    permute(S, 1, S.length() - 1, current, v);
    sort(v.begin(), v.end());

    return v;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        vector<string> ans;
        ans = permutation(S);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << "(" << ans[i] << ")";
        }
        cout << endl;
    }
}