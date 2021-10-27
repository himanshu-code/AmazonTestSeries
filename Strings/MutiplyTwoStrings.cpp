#include <bits/stdc++.h>
using namespace std;
string multiplyStrings(string str1, string str2)
{
    string s = "";
    if ((str1.at(0) == '-' || str2.at(0) == '-') && (str1.at(0) != '-' || str2.at(0) != '-'))
        s += "-";
    if (str1.at(0) == '-')
        str1 = str1.substr(1);

    if (str2.at(0) == '-')
        str2 = str2.substr(1);
    int len1 = str1.size();
    int len2 = str2.size();
    if (len1 == 0 || len2 == 0)
        return "0";
    vector<int> result(len1 + len2, 0);
    int i1 = 0, i2 = 0;
    for (int i = len1 - 1; i >= 0; i--)
    {
        int carry = 0;
        int n1 = str1[i] - '0';
        i2 = 0;
        for (int j = len2 - 1; j >= 0; j--)
        {
            int n2 = str2[j] - '0';
            int sum = (n1 * n2) + result[i1 + i2];
            carry = sum / 10;
            result[i1 + i2] = sum % 10;
            i2++;
        }
        if (carry > 0)
            result[i1 + i2] += carry;
        i1++;
    }
    int i = result.size() - 1;
    while (i >= 0 && result[i] == 0)
        i--;
    if (i == -1)
        return "0";

    while (i >= 0)
        s += to_string(result[i--]);
    return s;
}
int main()
{
    string str1, str2;
    cin >> str1;
    cin >> str2;
    cout << multiplyStrings(str1, str2);
}