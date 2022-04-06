
vector<string> solve(string s, set<string> &Dict,  unordered_map<string, vector<string>> &dp) {
    if (dp.find(s) != dp.end())  return dp[s];
    vector<string> result;
    for (string w : Dict) {
        if (s.substr(0, w.length()) == w) {
            if (w.length() == s.length()) {
                result.push_back(w);
            }
            else {
                vector<string> temp = solve(s.substr(w.length()), Dict, dp);
                for (string t : temp)
                    result.push_back(w + " " + t);
            }
        }
    }
    return dp[s] = result;
}

vector<string> Solution::wordBreak(string s, vector<string>& wordDict) {
    unordered_map<string, vector<string>> dp;
    set<string> Dict;
    for (auto x : wordDict)
        Dict.insert(x);
    solve(s, Dict, dp);
    return dp[s];
}

// https://www.interviewbit.com/problems/word-break-ii/