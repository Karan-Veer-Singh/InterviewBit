string Solution::solve(string A)
{
	map<char, int> m;
	string ans = "";

	for (char c : A)
		m[c]++;

	for (int i = 0; i < A.length(); i++)
	{
		char ch = A[i];

		if (m[ch] > 0)
		{
			ans += ch + to_string(m[ch]);
			m[ch] = 0;
		}
	}

	return ans;
}


// https://www.interviewbit.com/problems/string-and-its-frequency/