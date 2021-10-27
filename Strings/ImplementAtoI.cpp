#include <bits/stdc++.h>
using namespace std;
int atoi(string str)
{
    int sign = 1;
    int i = 0;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    int n = 0;
    while (i < str.length())
    {
        if (!isdigit(str[i]))
        {
            return -1;
        }
        n = n * 10;
        n += str[i] - '0';
        i++;
    }
    return n * sign;
}
int main()
{
    string str;
    cin >> str;
    cout << atoi(str);
}