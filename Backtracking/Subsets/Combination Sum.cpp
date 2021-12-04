void combination(int index, int target, vector<int> &candidates, vector<int> &v, vector<vector<int>>&ans)
{
    if (index == candidates.size())
    {
        if (target == 0)
            ans.push_back(v);

        return;
    }

    if (candidates[index] <= target)
    {
        v.push_back(candidates[index]);
        combination(index, target - candidates[index], candidates, v, ans);
        v.pop_back();
    }

    combination(index + 1, target, candidates, v, ans);
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> a;

    sort(A.begin(), A.end());

    a.push_back(A[0]);
    for (int i = 1; i < A.size(); i++)
        if (A[i - 1] != A[i])
            a.push_back(A[i]);

    combination(0, B, a, ds, ans);

    return ans;
}


// https://www.interviewbit.com/problems/combination-sum/