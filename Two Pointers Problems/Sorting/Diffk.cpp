int Solution::diffPossible(vector<int> &A, int k)
{
	int i = 0, j = 1;
	while (j < A.size())
	{
		int diff = A[j] - A[i];

		if (diff == k && i != j)     return 1;
		else if (diff > k)           i++;
		else                        j++;
	}

	return 0;
}


// https://www.interviewbit.com/problems/diffk/