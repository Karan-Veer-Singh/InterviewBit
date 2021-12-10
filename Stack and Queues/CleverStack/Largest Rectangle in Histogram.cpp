int Solution::largestRectangleArea(vector<int> &A)
{
	stack<int> s;
	int n = A.size();
	int maxA = 0;

	for (int i = 0; i <= n; i++)
	{
		while (!s.empty() && (i == n || A[i] <= A[s.top()]))
		{
			int height = A[s.top()];
			s.pop();

			int width;
			if (s.empty())
				width = i;
			else
				width = i - s.top() - 1;

			maxA = max(maxA, height * width);
		}

		s.push(i);
	}

	return maxA;
}

// https://www.interviewbit.com/problems/largest-rectangle-in-histogram/