#include <bits/stdc++.h>
using namespace std;
int MAX_CHAR = 26;
struct Key
{
    int freq;
    char ch;
    bool operator<(const Key &k) const
    {
        return freq < k.freq;
    }
};
string reArrange(string str)
{
    int n = str.length();
    int count[MAX_CHAR] = {0};
    for (int i = 0; i < n; i++)
    {
        count[str[i] - 'a']++;
    }
    priority_queue<Key> pq;
    for (char c = 'a'; c <= 'z'; c++)
    {
        if (count[c - 'a'])
            pq.push(Key{count[c - 'a'], c});
    }
    str = "";
    Key prev{-1, '#'};
    while (!pq.empty())
    {
        Key k = pq.top();
        pq.pop();
        str = str + k.ch;
        if (prev.freq > 0)
            pq.push(prev);
        (k.freq)--;
        prev = k;
    }
    if (n != str.length())
        return "-1";

    return str;
}
int main()
{
    string str;
    cin >> str;
    cout << reArrange(str);
}