int Solution::solve(vector<int> &A, int B, int C) {
	int odd = 0, even = 0;

	for (int e : A)
		if (e % 2) odd++;
		else    even++;

	if (B % 2) return even * C;
	else    return odd * C;
}


// https://www.interviewbit.com/problems/odd-even-rule/