//https://www.interviewbit.com/problems/longest-common-subsequence/

// TOP-DOWN (Memoization)
// Time Complexity = O(n*m)
// Sapce Complexity = O(n*m) + recursion stack space.

int dp[1005][1005];

int LCS(string &A, string &B, int n, int m)
{
    if (n == 0 || m == 0)
        return dp[n][m] = 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (A[n - 1] == B[m - 1])
        return dp[n][m] = 1 + LCS(A, B, n - 1, m - 1);

    return dp[n][m] = max(LCS(A, B, n - 1, m), LCS(A, B, n, m - 1));
}

int Solution::solve(string A, string B)
{
    int n = A.size();
    int m = B.size();

    memset(dp, -1, sizeof(dp));

    return LCS(A, B, n, m);
}


// Bottom-Up (Tabulation)
// Time Complexity = O(n*m)
// Sapce Complexity = O(n*m)
int Solution::solve(string A, string B)
{
    int n = A.size();
    int m = B.size();

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (A[i - 1] == B[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return dp[n][m];
}


// Space Optimised
// Time Complexity = O(n*m)
// Sapce Complexity = O(2*N)

int Solution::solve(string A, string B)
{
    int n = A.size();
    int m = B.size();

    int dp[2][m + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i % 2][j] = 0;

            else if (A[i - 1] == B[j - 1])
                dp[i % 2][j] = 1 + dp[(i + 1) % 2][j - 1];

            else
                dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[i % 2][j - 1]);
        }
    }


    return dp[n % 2][m];
}
