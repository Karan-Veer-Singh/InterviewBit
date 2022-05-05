
bool ispalindrome(string p) {
	int n = p.size();
	for (int i = 0; i <= n / 2; i++) {
		if (p[i] != p[n - i - 1]) return false;
	}
	return true;
}
string Solution::solve(string A) {
	int n = A.size();
	if (n == 1 && A[0] > '0' && A[0] <= '9') return "11";
	string m = "", temp = A; // for cases like 99999
	for (int i = 0; i < n; i++) m += '9';
	if (A == m) {
		string r = "1";
		for (int j = 0; j < n - 1; j++) r += '0';
		r += '1';
		return r;
	}
	if (ispalindrome(A)) { //check palindrome and if yes add 1
		int i = n - 1;
		while (A[i] == '9') {
			A[i] = '0';
			i--;
		}
		A[i] = A[i] + 1;
	}
	if (n % 2 == 0) { // for even length string
		string l = A.substr(0, n / 2);
		string r = A.substr(n / 2, n / 2);
		string p = l;
		reverse(l.begin(), l.end());
		if (l > r) {
//if reverse of left string is greater then right
//then simply return the created string
			return p + l;
		}
		else {
// if not then add 1 to left string and then
//return the string while concatinating its reverse
			int i = p.size() - 1;
			while (p[i] == '9') {
				p[i] = '0';
				i--;
			}
			p[i] = p[i] + 1;
			//cout<<p<<"\n";
			l = p;
			reverse(p.begin(), p.end());
			return l + p;
		}
	}
	else { // for odd length string
		string l = A.substr(0, n / 2);
		string r = A.substr((n / 2) + 1, n / 2);
		string p = l;
		reverse(l.begin(), l.end());
		if (l > r) {
			return p + A[n / 2] + l;
		}
		else {
			p += A[n / 2];
			int i = p.size() - 1;
			while (p[i] == '9') {
				p[i] = '0';
				i--;
			}
			p[i] = p[i] + 1;
			l = p;
			int k = p.size();
			p = p.substr(0, k - 1);
			reverse(p.begin(), p.end());
			return l + p;
		}
	}
}