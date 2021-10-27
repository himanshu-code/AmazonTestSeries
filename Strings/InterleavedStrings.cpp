#include <bits/stdc++.h>
using namespace std;
bool isInterleaving(string A, string B, string C)
{
    int m = A.length();
    int n = B.length();
    bool dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    if (m + n != C.length())
        return false;

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                if (B[j - 1] == C[j - 1])
                    dp[i][j] == dp[i][j - 1];
            }
            else if (j == 0)
            {
                if (A[i - 1] == C[i - 1])
                    dp[i][j] = dp[i - 1][j];
            }
            else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1])
                dp[i][j] = dp[i - 1][j];
            else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1])
                dp[i][j] = dp[i][j - 1];

            else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1])
                dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
int main()
{
    string A, B, C;
    cin >> A >> B >> C;
    if (isInterleaving(A, B, C))
    {
        cout << "True";
    }
    else
        cout << "False";
}