vector<int> Solution::wave(vector<int> &A)
{
	sort(A.begin(), A.end());

	for (int i = 1; i < A.size(); i += 2)
		swap(A[i - 1], A[i]);

	return A;
}


// https://www.interviewbit.com/problems/wave-array/