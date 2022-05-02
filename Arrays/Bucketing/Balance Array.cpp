int Solution::solve(vector<int> &A) {
	int count = 0, odd = 0, even = 0;

	for (int i = 0; i < A.size(); i++)
		if (i % 2 == 0)	even += A[i];
		else	odd += A[i];

	for (int i = A.size() - 1; i >= 0; i--) {
		if (i % 2 == 0) even -= A[i];
		else odd -= A[i];

		if (odd == even) count++;

		if (i % 2 == 0) odd += A[i];
		else even += A[i];
	}
	return count;
}

// https://www.interviewbit.com/problems/balance-array/