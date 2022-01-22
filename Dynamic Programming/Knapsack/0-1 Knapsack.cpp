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
