int Solution::solve(string A)
{
    int open = 0, close = 0;

    for (int i = 0; A[i]; i++)
    {
        open += A[i] == '(' ? 1 : -1;

        if (open == -1)
        {
            close++;
            open = 0;
        }
    }

    return open + close;
}


// https://www.interviewbit.com/problems/minimum-parantheses/