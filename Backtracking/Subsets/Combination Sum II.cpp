void combination(int index, vector<int> A, int target, vector<int> &ds, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    for (int i = index; i < A.size(); i++)
    {
        if (i != index && A[i - 1] == A[i])
            continue;

        if (A[i] > target)
            break;

        ds.push_back(A[i]);
        combination(i + 1, A, target - A[i], ds, ans);
        ds.pop_back();
    }
}

vector<vector<int> > Solution::combinationSum(vector<int> &A, int B)
{
    vector<vector<int>> ans;
    vector<int> ds;

    sort(A.begin(), A.end());
    combination(0, A, B, ds, ans);

    return ans;
}

// https://www.interviewbit.com/problems/combination-sum-ii/