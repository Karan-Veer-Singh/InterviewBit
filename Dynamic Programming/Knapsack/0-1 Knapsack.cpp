// https://www.interviewbit.com/problems/0-1-knapsack/

// TOP-DOWN (Memoization)
// Time Complexity = O(n*m)
// Sapce Complexity = O(n*m) + recursion stack space.

int knapsack(vector<int> &val, vector<int> &weight, int capacity, int n, vector<vector<int>> &dp)
{
    if (n == 0 || capacity == 0)
        return 0;

    if (dp[n][capacity] != -1)
        return dp[n][capacity];

    if (weight[n - 1] <= capacity)
    {
        int inc = val[n - 1] + knapsack(val, weight, capacity - weight[n - 1], n - 1, dp);
        int exc = knapsack(val, weight, capacity, n - 1, dp);

        return dp[n][capacity] = max(inc, exc);
    }
    else
    {
        return dp[n][capacity] = knapsack(val, weight, capacity, n - 1, dp);
    }
}

int Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    int n = A.size();

    vector<vector<int>> dp(n + 1, vector<int>(C + 1, -1));

    return knapsack(A, B, C, n, dp);
}


// Bottom-Up (Tabulation)
// Time Complexity = O(N*C)
// Sapce Complexity = O(N*C)

int Solution::solve(vector<int> &val, vector<int> &weight, int C)
{
    int N = val.size();

    int dp[N + 1][C + 1];

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;

            else if (weight[i - 1] <= j)
            {
                int inc = val[i - 1] + dp[i - 1][j - weight[i - 1]];
                int exc = dp[i - 1][j];

                dp[i][j] = max(inc, exc);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[N][C];
}


// Space Optimised
// Time Complexity = O(N*C)
// Sapce Complexity = O(2*C)
int Solution::solve(vector<int> &val, vector<int> &weight, int C)
{
    int N = val.size();

    int dp[2][C + 1];

    for (int i = 0; i <= N; i++)
    {
        for (int j = 0; j <= C; j++)
        {
            if (i == 0 || j == 0)
                dp[i % 2][j] = 0;

            else if (weight[i - 1] <= j)
            {
                int inc = val[i - 1] + dp[(i - 1) % 2][j - weight[i - 1]];
                int exc = dp[(i - 1) % 2][j];

                dp[i % 2][j] = max(inc, exc);
            }
            else
            {
                dp[i % 2][j] = dp[(i - 1) % 2][j];
            }
        }
    }

    return dp[N % 2][C];
}
