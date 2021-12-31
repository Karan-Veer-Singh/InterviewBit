int Solution::numSetBits(unsigned int A)
{
	int ans = 0;
	while (A > 0)
	{
		ans++;
		A = A & (A - 1);
	}

	return ans;
}


// https://www.interviewbit.com/problems/number-of-1-bits/