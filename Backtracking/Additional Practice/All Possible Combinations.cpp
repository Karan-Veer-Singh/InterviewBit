void solve(vector <string> &A, vector <string> &ans, int index, string &s) {
    if (s.length() == A.size()) {
        ans.push_back(s);
    }
    for (int i = index; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            s.push_back(A[i][j]);
            solve(A, ans, i + 1, s);
            s.pop_back();
        }
    }
}
vector<string> Solution::specialStrings(vector<string> &A) {
    vector <string> ans;
    string s;
    solve(A, ans, 0, s);
    return ans;
}

// https://www.interviewbit.com/problems/all-possible-combinations/