#include <bits/stdc++.h>
using namespace std;
int ExcelColumn(string str)
{
    int n = 0;
    for (int i = 0; i < str.length(); i++)
    {
        n = n * 26;
        int k = str[i] - 'A';
        n = n + k + 1;
    }
    return n;
}
int main()
{
    string str;
    cin >> str;
    cout << ExcelColumn(str);
}