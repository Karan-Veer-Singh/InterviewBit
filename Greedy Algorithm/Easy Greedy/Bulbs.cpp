int Solution::bulbs(vector<int> &A)
{
	int switchCount = 0;
	for (int i = 0; i < A.size(); i++)
	{
		if (switchCount % 2 != 0)
			A[i] = 1 - A[i];

		if (A[i] == 0)
			switchCount++;
	}

	return switchCount;
}


// https://www.interviewbit.com/problems/interview-questions/