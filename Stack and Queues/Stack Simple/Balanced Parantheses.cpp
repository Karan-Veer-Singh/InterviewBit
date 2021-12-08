int Solution::solve(string A)
{
    int length = A.length();
    stack<char> s;

    for (int i = 0; i < length; i++)
    {
        if (A[i] == ')')
            if (s.empty() || s.top() != '(')
                return 0;
            else
                s.pop();

        else
            s.push(A[i]);
    }

    if (s.empty())
        return 1;
    else
        return 0;
}


// https://www.interviewbit.com/problems/balanced-parantheses/