int Solution::maxp3(vector<int> &A)
{
	int n = A.size();
	if (n < 3)
		return 0;

	sort(A.begin(), A.end());
	return max(A[n - 1] * A[n - 2] * A[n - 3], A[n - 1] * A[0] * A[1]);
}


// https://www.interviewbit.com/problems/highest-product/