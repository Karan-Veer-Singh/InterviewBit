string Solution::serialize(vector<string> &A)
{
	string ans = "";

	for (auto s : A)
		ans += s + to_string(s.length()) + '~';

	return ans;
}


// https://www.interviewbit.com/problems/serialize/