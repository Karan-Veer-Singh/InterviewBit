int Solution::braces(string A)
{
    stack<char> s;
    int len_A = A.length();

    for (int i = 0; i < len_A; i++)
    {
        char ch = A[i];

        if (ch == ')')
        {
            int count = 0;

            while (!s.empty() && s.top() != '(')
            {
                s.pop();
                count++;
            }
            s.pop();

            if (count <= 1)
                return 1;
        }
        else
            s.push(ch);
    }

    return 0;
}


// https://www.interviewbit.com/problems/redundant-braces/