int Solution::singleNumber(const vector<int> &A)
{
	int ans = 0;
	for (int x : A)
		ans ^= x;

	return ans;
}


// https://www.interviewbit.com/problems/single-number/