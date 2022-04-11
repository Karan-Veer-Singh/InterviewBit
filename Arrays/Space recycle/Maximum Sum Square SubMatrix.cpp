int Solution::solve(vector<vector<int> > &A, int B) {
    int r = A.size(), c = A[0].size();
    int maxSum = INT_MIN;
    vector<vector<int>> prefixSum(r + 1, vector<int>(c + 1, 0));

    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            prefixSum[i][j] = A[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            int sum = INT_MIN;
            if (i - B >= 0 && j - B >= 0) {
                sum = prefixSum[i][j] - prefixSum[i - B][j] - prefixSum[i][j - B] + prefixSum[i - B][j - B];
                maxSum = max(maxSum, sum);
            }
        }
    }
    return maxSum;
}

// https://www.interviewbit.com/problems/maximum-sum-square-submatrix/