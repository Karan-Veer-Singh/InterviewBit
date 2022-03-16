vector<int> Solution::solve(vector<int> &A)
{
	vector<int> ans;

	int neg = 0, pos = 0;

	for (int val : A)
		if (val < 0) neg++;
		else if (val > 0)   pos++;

	ans.push_back(pos);
	ans.push_back(neg);
	return ans;
}


// https://www.interviewbit.com/problems/positive-negative/