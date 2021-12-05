bool palindrome(string A, int s, int e)
{
    while (s <= e)
    {
        if (A[s++] != A[e--])
            return false;
    }
    return true;
}

void solve(int index, string A, vector<string> &s, vector<vector<string>> &ans)
{
    if (index == A.size())
    {
        ans.push_back(s);
        return;
    }

    for (int i = index; i < A.size(); i++)
    {
        if (palindrome(A, index, i))
        {
            s.push_back(A.substr(index, i - index + 1));
            solve(i + 1, A, s, ans);
            s.pop_back();
        }
    }
}


vector<vector<string> > Solution::partition(string A)
{
    vector<vector<string>> ans;
    vector<string> s;

    solve(0, A, s, ans);

    return ans;
}

// https://www.interviewbit.com/problems/palindrome-partitioning/