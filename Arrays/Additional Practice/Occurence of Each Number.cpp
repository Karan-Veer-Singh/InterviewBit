vector<int> Solution::findOccurences(vector<int> &A)
{
	map<int, int> m;
	vector<int> v;

	for (int i = 0; i < A.size(); i++)
		m[A[i]]++;


	for (auto it : m)
		v.push_back(it.second);

	return v;
}


// https://www.interviewbit.com/problems/occurence-of-each-number/