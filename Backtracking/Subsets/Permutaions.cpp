void permutation(int index, vector<int> &A, vector<vector<int>> &ans)
{
    if (index == A.size())
    {
        ans.push_back(A);
        return;
    }

    for (int i = index; i < A.size(); i++)
    {
        swap(A[i], A[index]);
        permutation(index + 1, A, ans);
        swap(A[i], A[index]);
    }
}

vector<vector<int> > Solution::permute(vector<int> &A)
{
    vector<vector<int>> ans;
    permutation(0, A, ans);
    return ans;
}


// https://www.interviewbit.com/problems/permutations/