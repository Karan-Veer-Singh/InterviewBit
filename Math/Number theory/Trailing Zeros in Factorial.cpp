int Solution::trailingZeroes(int A)
{
	int p = 5;
	int ans = 0;

	while ( (A / p) > 0)
	{
		ans += (A / p);
		p *= 5;
	}

	return ans;
}


// https://www.interviewbit.com/problems/trailing-zeros-in-factorial/