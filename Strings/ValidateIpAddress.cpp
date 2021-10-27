#include <bits/stdc++.h>
using namespace std;
int validateIp(string str)
{
    int counter = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
            counter++;
    }
    if (counter != 3)
        return 0;
    unordered_set<string> st;
    counter = 0;
    for (int i = 0; i < 256; i++)
    {
        st.insert(to_string(i));
    }
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != '.')
        {
            temp += str[i];
        }
        else
        {
            if (st.count(temp) != 0)
                counter++;
            temp = "";
        }
    }
    if (st.count(temp) != 0)
        counter++;
    if (counter == 4)
        return 1;
    else
        return 0;
}
int main()
{
    string str;
    cin >> str;
    cout << validateIp(str);
}