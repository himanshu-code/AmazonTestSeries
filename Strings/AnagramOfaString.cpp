#include <bits/stdc++.h>
using namespace std;
int CountRem(string str1, string str2)
{
    int alpha[26] = {0};
    int ans = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        alpha[str1[i] - 'a']++;
    }
    for (int i = 0; i < str2.length(); i++)
    {
        alpha[str2[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        ans += abs(alpha[i]);
    }
    return ans;
}
int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << CountRem(str1, str2);
}