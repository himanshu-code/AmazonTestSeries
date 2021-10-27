#include <bits/stdc++.h>
using namespace std;
void pclosest(vector<vector<int>> pts, int k)
{
    multimap<int, int> m;
    for (int i = 0; i < pts.size(); i++)
    {
        int x = pts[i][0], y = pts[i][1];
        m.insert({(x * x) + (y * y), i});
    }
    for (auto it = m.begin(); it != m.end() && k > 0; it++, k--)
    {
        cout << "[" << pts[it->second][0] << " "
             << ", " << pts[it->second][1] << "]" << endl;
    }
}
int main()
{
    vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;
    pclosest(points, k);
    return 0;
}