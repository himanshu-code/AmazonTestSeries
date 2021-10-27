#include <bits/stdc++.h>
using namespace std;
string lengthEncode(string str)
{
    string ans = "";
    char prev = str[0];
    int count = 1;
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == prev)
            count++;
        else
        {
            ans.push_back(prev);
            ans.append(to_string(count));
            prev = str[i];
            count = 1;
        }
    }
    ans.push_back(prev);
    ans.append(to_string(count));
    return ans;
}
int main()
{
    string str;
    cin >> str;
    cout << lengthEncode(str);
}