#include <bits/stdc++.h>
using namespace std;
vector<string> v;
void permutations(string str, int i)
{
    if (str[i] == '\0')
    {
        v.push_back(str);
        return;
    }
    for (int j = i; str[j] != '\0'; j++)
    {
        swap(str[i], str[j]);
        permutations(str, i + 1);
        swap(str[i], str[j]);
    }
}
vector<string> find_permutation(string str)
{
    permutations(str, 0);
    sort(v.begin(), v.end());
    return v;
}
int main()
{
    string str;
    cin >> str;
    vector<string> ans = find_permutation(str);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}