
void subset(int index, vector<int> A, vector<int> &ds, vector<vector<int>> &ans)
{
  if (index == A.size())
  {
    ans.push_back(ds);
    return;
  }

  ds.push_back(A[index]);
  subset(index + 1, A, ds, ans);

  ds.pop_back();
  subset(index + 1, A, ds, ans);
}

vector<vector<int> > Solution::subsets(vector<int> &A)
{
  vector<vector<int>> ans;
  vector<int> ds;

  sort(A.begin(), A.end());

  subset(0, A, ds, ans);

  sort(ans.begin(), ans.end());

  return ans;
}
