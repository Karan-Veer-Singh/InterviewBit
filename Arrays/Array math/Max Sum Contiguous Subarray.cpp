int Solution::maxSubArray(const vector<int> &A)
{
	int sum = 0;
	int maxi = INT_MIN;

	for (int x : A)
	{
		sum += x;
		maxi = max(maxi, sum);
		if (sum < 0) sum = 0;
	}

	return maxi;
}


// https://www.interviewbit.com/problems/max-sum-contiguous-subarray/