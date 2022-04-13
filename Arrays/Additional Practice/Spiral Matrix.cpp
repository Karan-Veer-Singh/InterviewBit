vector<vector<int> > Solution::solve(vector<int> &A, int B, int C) {
    vector<vector<int>> v(B, vector<int>(C,  0));
    int t = 0, b = B - 1;
    int l = 0, r = C - 1;
    int dir = 0;
    int indx = 0;

    while (l <= r && t <= b)
    {
        if (dir == 0)
        {
            for (int i = l; i <= r; i++)
                v[t][i] = A[indx++];
            t++;
        }
        else if (dir == 1)
        {
            for (int i = t; i <= b; i++)
                v[i][r] = A[indx++];
            r--;
        }
        else if (dir == 2)
        {
            for (int i = r; i >= l; i--)
                v[b][i] = A[indx++];
            b--;
        }
        else if (dir == 3)
        {
            for (int i = b; i >= t; i--)
                v[i][l] = A[indx++];
            l++;
        }

        dir = (dir + 1) % 4;
    }

    return v;
}


// https://www.interviewbit.com/problems/spiral-matrix/