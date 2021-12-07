string ans;

void maximal(string s, int k)
{
    if (s > ans)
        ans = s;

    if (k == 0)
        return;

    for (int i = 0; i < s.size() - 1; i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            swap(s[i], s[j]);
            maximal(s, k - 1);
            swap(s[i], s[j]);
        }
    }
}

string Solution::solve(string A, int B)
{
    ans = A;
    maximal(A, B);
    return ans;
}


// https://www.interviewbit.com/problems/maximal-string/