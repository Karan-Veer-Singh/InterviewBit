void Solution::merge(vector<int> &A, vector<int> &B)
{
	int pa = A.size() - 1;
	int pb = B.size() - 1;
	int pc = A.size() + B.size() - 1;

	A.resize(A.size() + B.size());

	while (pb >= 0)
	{
		if (pa >= 0 and A[pa] > B[pb])    A[pc--] = A[pa--];
		else    A[pc--] = B[pb--];
	}
}


// https://www.interviewbit.com/problems/merge-two-sorted-lists-ii/