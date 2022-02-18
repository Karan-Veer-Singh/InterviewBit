vector<int> Solution::getRow(int i)
{
	vector<int> ans;

	int val = 1;

	for (int j = 0; j <= i; j++)
	{
		ans.push_back(val);
		val = val * (i - j) / (j + 1);
	}

	return ans;
}


// https://www.interviewbit.com/problems/kth-row-of-pascals-triangle/