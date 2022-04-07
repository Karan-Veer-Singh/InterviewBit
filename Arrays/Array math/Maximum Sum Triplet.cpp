int Solution::solve(vector<int> &A) {
    int n = A.size();
    int maxSuffixArr[n + 1] = {0};
    for (int i = n - 1; i >= 0; i--)
        maxSuffixArr[i] = max(maxSuffixArr[i + 1], A[i]);

    int ans = 0;
    set<int> lowValue;
    lowValue.insert(INT_MIN);
    for (int i = 0; i < n - 1; i++) {
        lowValue.insert(A[i]);
        auto it = lowValue.find(A[i]);
        int left = *(--it);

        if (maxSuffixArr[i + 1] > A[i])
            ans = max(ans, (left + A[i] + maxSuffixArr[i + 1]));
    }

    return ans;
}


// https://www.interviewbit.com/problems/maximum-sum-triplet/