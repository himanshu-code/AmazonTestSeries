#include <bits/stdc++.h>
using namespace std;
int isValid(string &ip)
{
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            ips.push_back(ex);
            ex = "";
        }
        else
        {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);
    for (int i = 0; i < ips.size(); i++)
    {
        if (ips[i].length() > 3 || stoi(ips[i]) < 0 || stoi(ips[i]) > 255)
            return 0;

        if (ips[i].length() > 1 && stoi(ips[i]) == 0)
            return 0;
        if (ips[i].length() > 1 && stoi(ips[i]) != 0 && ips[i][0] == '0')
            return 0;
    }
    return 1;
}
vector<string> genIp(string &str)
{
    vector<string> v;
    int l = str.length();
    string check = str;
    for (int i = 1; i < l - 2; i++)
    {
        for (int j = i + 1; j < l - 1; j++)
        {
            for (int k = j + 1; k < l; k++)
            {
                check = check.substr(0, k) + "." + check.substr(k);
                check = check.substr(0, j) + "." + check.substr(j);
                check = check.substr(0, i) + "." + check.substr(i);
                if (isValid(check))
                {
                    v.push_back(check);
                }
                check = str;
            }
        }
    }
    return v;
}
int main()
{
    string str;
    cin >> str;
    vector<string> ans = genIp(str);
    for (auto x : ans)
    {
        cout << x << " ";
    }
}