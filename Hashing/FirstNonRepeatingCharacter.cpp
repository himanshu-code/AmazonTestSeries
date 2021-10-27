#include <bits/stdc++.h>
using namespace std;
char NonRepeatingCharacter(string str)
{
    unordered_map<char, int> m;
    for (int i = 0; i < str.length(); i++)
    {
        m[str[i]]++;
    }
    for (int i = 0; i < str.length(); i++)
    {
        if (m[str[i]] == 1)
            return str[i];
    }
    return '$';
}
int main()
{
    string str;
    cin >> str;
    cout << NonRepeatingCharacter(str);
}