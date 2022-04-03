int Solution::minPathSum(vector<vector<int> > &grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<int> prev(n, 0);
    vector<int> curr(n, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];

            else
            {
                int up = grid[i][j];
                up += (i > 0) ? prev[j] : 1e9;

                int left = grid[i][j];
                left += (j > 0) ? curr[j - 1] : 1e9;

                curr[j] = min(up, left);
            }
        }

        prev = curr;
    }

    return prev[n - 1];
}

// https://www.interviewbit.com/problems/min-sum-path-in-matrix/