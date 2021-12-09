int Solution::evalRPN(vector<string> &A)
{
    stack<int> s;

    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == "+" || A[i] == "/" || A[i] == "*" || A[i] == "-")
        {
            int operand2 = s.top();
            s.pop();

            int operand1 = s.top();
            s.pop();

            int ans;
            if (A[i] == "+")
                ans = operand1 + operand2;
            else if (A[i] == "-")
                ans = operand1 - operand2;
            else if (A[i] == "*")
                ans = operand1 * operand2;
            else if (A[i] == "/")
                ans = operand1 / operand2;

            s.push(ans);
        }
        else
        {
            int e = stoi(A[i]);
            s.push(e);
        }
    }

    return s.top();
}


// https://www.interviewbit.com/problems/evaluate-expression/