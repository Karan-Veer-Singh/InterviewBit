int Solution::lis(const vector<int> &A) {
    int n = A.size();
    int maxi = 1;
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = INT_MIN;

    for (int i = 0; i < n; i++) {
        int length = upper_bound(dp.begin(), dp.end(), A[i]) - dp.begin();
        if (A[i] > dp[length - 1] && A[i] < dp[length]) {
            dp[length] = A[i];
            maxi = max(maxi, length);
        }
    }
    return maxi;
}

// https://www.interviewbit.com/problems/longest-increasing-subsequence/