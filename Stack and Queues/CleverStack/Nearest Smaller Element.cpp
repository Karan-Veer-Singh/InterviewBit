vector<int> Solution::prevSmaller(vector<int> &A)
{
    int n = A.size();
    vector<int> ans(n, -1);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        int element = A[i];
        while (!s.empty() && s.top() >= element)
            s.pop();

        if (!s.empty())
            ans[i] = s.top();

        s.push(element);
    }

    return ans;
}


// https://www.interviewbit.com/problems/nearest-smaller-element/