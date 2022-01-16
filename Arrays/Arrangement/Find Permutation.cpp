vector<int> Solution::findPerm(const string A, int B)
{
	vector<int> ans;
	int low = 1;
	int high = B;

	for (int i = 0; i <= A.size(); i++)
		if (A[i] == 'I')
			ans.push_back(low++);
		else
			ans.push_back(high--);

	return ans;
}


// https://www.interviewbit.com/problems/find-permutation/