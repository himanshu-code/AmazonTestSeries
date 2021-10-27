#include <bits/stdc++.h>
using namespace std;
string reversedWords(string str)
{
    vector<string> v;
    string s = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            v.push_back(s);
            v.push_back(".");
            s = "";
        }
        else
            s += str[i];
    }
    v.push_back(s);
    reverse(v.begin(), v.end());
    s = "";
    for (int i = 0; i < v.size(); i++)
    {
        s += v[i];
    }
    return s;
}
int main()
{
    string str;
    cin >> str;
    cout << reversedWords(str);
}