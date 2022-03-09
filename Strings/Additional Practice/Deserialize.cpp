vector<string> Solution::deserialize(string A)
{
	vector<string> v;
	string s = "";

	for (int i = 0; i < A.length();)
	{
		while (isalpha(A[i])) {
			s += tolower(A[i]);
			i++;
		}

		v.push_back(s);
		s = "";

		while (!isalpha(A[i])) {
			i++;
		}

	}

	return v;
}

// https://www.interviewbit.com/problems/deserialize/