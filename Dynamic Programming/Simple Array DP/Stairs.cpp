int Solution::climbStairs(int n)
{
	int dp[n + 1];

	dp[0] = dp[1] = 1;

	for (int i = 2; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 2];

	return dp[n];
}


////////////////////////////////////

int Solution::climbStairs(int n)
{
	if (n == 0 || n == 1)
		return 1;

	int prev1 = 1;
	int prev2 = 1;

	int ans;
	for (int i = 2; i <= n; i++)
	{
		ans = prev1 + prev2;
		prev1 = prev2;
		prev2 = ans;
	}

	return ans;
}


// https://www.interviewbit.com/problems/stairs/