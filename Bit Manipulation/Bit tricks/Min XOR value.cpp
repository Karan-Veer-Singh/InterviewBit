int Solution::findMinXor(vector<int> &A)
{
	sort(A.begin(), A.end());
	int ans = INT_MAX;

	for (int i = 0; i < A.size() - 1; i++)
	{
		int x = A[i] ^ A[i + 1];
		ans = min(ans, x);
	}

	return ans;
}


// https://www.interviewbit.com/problems/min-xor-value/