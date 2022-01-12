int Solution::titleToNumber(string A)
{
	int ans = 0;
	for (char c : A)
	{
		int d = c - 'A' + 1;
		ans = (ans * 26) + d;
	}

	return ans;
}


// https://www.interviewbit.com/problems/excel-column-number/