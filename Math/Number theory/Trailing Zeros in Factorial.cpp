int Solution::trailingZeroes(int n)
{
	int ans = 0;

	while (n)
	{
		n /= 5;
		ans += n;
	}

	return ans;
}



// https://www.interviewbit.com/problems/trailing-zeros-in-factorial/