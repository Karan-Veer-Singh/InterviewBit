int Solution::solve(vector<int> &A) {
	unordered_map<int, int> m;
	for (int e : A)  m[e]++;

	int ans = 0;
	for (auto p : m)
		if (p.second >= 2)
			ans += (p.second / 2);

	return ans;
}


// https://www.interviewbit.com/problems/socks-pair/