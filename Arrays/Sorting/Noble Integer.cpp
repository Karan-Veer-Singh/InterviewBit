int Solution::solve(vector<int> &A) {
	int n = A.size();
	sort(A.begin(), A.end());

	if (A[n - 1] == 0)	return 1;

	for (int i = 0; i < n - 1; i++) {
		if (A[i] == A[i + 1])	continue;
		if (A[i] == n - i - 1)	return 1;
	}
	return -1;
}

// TC- O(NlogN)

// https://www.interviewbit.com/problems/noble-integer/