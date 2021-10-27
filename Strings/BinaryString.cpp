#include <bits/stdc++.h>
using namespace std;
long binarySubstring(string str)
{
    int n = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
            n++;
    }
    return n * (n - 1) / 2;
}
int main()
{
    string str;
    cin >> str;
    cout << binarySubstring(str);
}