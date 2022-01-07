vector<int> Solution::solve(vector<int> &A)
{
	int j = 0;
	for (int i = 0; i < A.size(); i++)
		if (A[i] == 0)
			swap(A[i], A[j++]);

	return A;
}


// Time Complexity: O(N).

// https://www.interviewbit.com/problems/segregate-0s-and-1s-in-an-array/