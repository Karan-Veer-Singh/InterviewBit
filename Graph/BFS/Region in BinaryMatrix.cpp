int area(vector<vector<int>>& grid , int i, int j, vector<int> &dx, vector<int> &dy) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 ) return 0;

    grid[i][j] = 0;
    int ans = 0;

    for (int k = 0; k < 8; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        ans += area(grid, x, y, dx, dy);
    }
    return 1 + ans;
}

int Solution::solve(vector<vector<int> > &grid) {
    int n = grid.size(), m = grid[0].size(), ans = 0;

    vector<int> dx = {0, 0, 1, -1, -1, -1, 1, 1};
    vector<int> dy = {1, -1, 0, 0, -1, 1, -1, 1};

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (grid[i][j] == 1)
                ans = max(ans, area(grid, i, j, dx, dy));

    return ans;
}

// https://www.interviewbit.com/problems/region-in-binarymatrix/