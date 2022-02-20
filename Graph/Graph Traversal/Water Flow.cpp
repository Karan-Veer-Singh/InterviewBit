void dfs(vector<vector<int>> &matrix, int i, int j, int prev, vector<vector<int>> &ocean)
{
    if (i < 0 || i >= ocean.size() || j < 0 || j >= ocean[0].size())
        return;

    if (matrix[i][j] < prev || ocean[i][j])
        return;

    ocean[i][j] = 1;

    dfs(matrix, i + 1, j, matrix[i][j], ocean);
    dfs(matrix, i, j + 1, matrix[i][j], ocean);
    dfs(matrix, i - 1, j, matrix[i][j], ocean);
    dfs(matrix, i, j - 1, matrix[i][j], ocean);
}

int Solution::solve(vector<vector<int> > &matrix)
{
    int count = 0;
    if (matrix.size() < 1)
        return count;

    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> blue(row, vector<int>(col, 0));
    vector<vector<int>> red(row, vector<int>(col, 0));

    for (int i = 0; i < col; i++)
    {
        dfs(matrix, 0, i, INT_MIN, blue);
        dfs(matrix, row - 1, i, INT_MIN, red);
    }

    for (int i = 0; i < row; i++)
    {
        dfs(matrix, i, 0, INT_MIN, blue);
        dfs(matrix, i, col - 1, INT_MIN, red);
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (blue[i][j] && red[i][j])
                count++;

    return count;
}

// https://www.interviewbit.com/problems/water-flow/