int Solution::anytwo(string A)
{
    string B = A;
    int n = A.size();

    int dp[n + 1][n + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (A[i - 1] == B[j - 1] && i != j)
                dp[i][j] = 1 + dp[i - 1][j - 1];

            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    return (dp[n][n] >= 2) ? 1 : 0;
}


// https://www.interviewbit.com/problems/repeating-subsequence/