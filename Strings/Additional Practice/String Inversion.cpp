string Solution::solve(string A)
{
	for (char &c : A)
		if (c >= 'a' && c <= 'z')
			c -= 32;
		else
			c += 32;

	return A;
}


// https://www.interviewbit.com/problems/string-inversion/