void solve(int index, int n, int k, vector<int> &ds, vector<vector<int>> &ans)
{
    if (ds.size() == k)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = index; i <= n; i++)
    {
        ds.push_back(i);
        solve(i + 1, n, k, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int> > Solution::combine(int n, int k)
{
    vector<int> ds;
    vector<vector<int>> ans;

    solve(1, n, k, ds, ans);

    return ans;
}


// https://www.interviewbit.com/problems/combinations/