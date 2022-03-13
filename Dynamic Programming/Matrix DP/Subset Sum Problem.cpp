// Memoization

bool subsetSum(int i, int target, vector<int> &A, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;

    if (i == 0)
        return A[i] == target;

    if (dp[i][target] != -1)
        return dp[i][target];

    bool notTake = subsetSum(i - 1, target, A, dp);
    bool take = false;
    if (A[i] <= target)
        take = subsetSum(i - 1, target - A[i], A, dp);

    return dp[i][target] = take || notTake;
}

int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(B + 1, -1));
    return subsetSum(n - 1, B, A, dp);
}


__________________________________________________________________________
// Tabulation

int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    vector<vector<bool>> dp(n, vector<bool>(B + 1, 0));

    for (int i = 0; i < n; i++)  dp[i][0] = true;

    if (A[0] <= B)  dp[0][A[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= B; target++)
        {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (A[i] <= target)
                take = dp[i - 1][target - A[i]];

            dp[i][target] = take || notTake;
        }
    }

    return dp[n - 1][B];
}

__________________________________________________________________________
// Tabulation (Space Optimized)

int Solution::solve(vector<int> &A, int B)
{
    int n = A.size();
    vector<bool> prev(B + 1, 0), curr(B + 1, 0);

    prev[0] = curr[0] = true;

    if (A[0] <= B)  prev[A[0]] = true;

    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= B; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if (A[i] <= target)
                take = prev[target - A[i]];

            curr[target] = take || notTake;
        }

        prev = curr;
    }

    return prev[B];
}

// https://www.interviewbit.com/problems/subset-sum-problem/