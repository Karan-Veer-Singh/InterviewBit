vector<int> Solution::repeatedNumber(const vector<int> &A)
{
	vector<int> ans;

	int n = A.size();
	int xorr = 0;

	for (int val : A)
		xorr ^= val;

	for (int i = 1; i <= n; i++)
		xorr ^= i;

	int rsb = xorr & -xorr;
	int x = 0;
	int y = 0;

	for (int val : A)
		(val & rsb) ? (x ^= val) : (y ^= val);

	for (int i = 1; i <= n; i++)
		(i & rsb) ? (x ^= i) : (y ^= i);

	for (int val : A)
		if (val == x) {
			ans.push_back(x);
			ans.push_back(y);
			break;
		}
		else if (val == y) {
			ans.push_back(y);
			ans.push_back(x);
			break;
		}

	return ans;
}


// https://www.interviewbit.com/problems/repeat-and-missing-number-array/