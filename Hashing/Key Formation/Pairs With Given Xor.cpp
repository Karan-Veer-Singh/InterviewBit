int Solution::solve(vector<int> &A, int k)
{
	map<int, int> m;
	int count = 0;

	for (int i = 0; i < A.size(); i++)
	{
		int curr = A[i];
		int target = curr ^ k;

		if (m.find(target) != m.end())
			count++;

		m[curr]++;
	}

	return count;
}


// https://www.interviewbit.com/problems/pairs-with-given-xor/