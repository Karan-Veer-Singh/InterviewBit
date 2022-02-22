void Solution::setZeroes(vector<vector<int> > &A)
{
    int col0 = 1;
    int row = A.size();
    int col = A[0].size();

    for (int i = 0; i < row; i++)
    {
        if (A[i][0] == 0)
            col0 = 0;

        for (int j = 1; j < col; j++)
        {
            if (A[i][j] == 0)
            {
                A[i][0] = 0;
                A[0][j] = 0;
            }
        }
    }

    for (int i = row - 1; i >= 0; i--)
    {
        for (int j = col - 1; j >= 1; j--)
        {
            if (A[i][0] == 0 || A[0][j] == 0)
                A[i][j] = 0;
        }

        if (col0 == 0)
            A[i][0] = 0;
    }
}


// https://www.interviewbit.com/problems/set-matrix-zeros/