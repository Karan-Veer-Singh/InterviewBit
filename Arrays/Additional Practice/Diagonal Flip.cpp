vector<vector<int> > Solution::solve(vector<vector<int> > &A)
{
	for (int i = 0; i < A.size(); i++)
		for (int j = i + 1; j < A[i].size(); j++)
			swap(A[i][j], A[j][i]);

	return A;
}


// https://www.interviewbit.com/problems/diagonal-flip/