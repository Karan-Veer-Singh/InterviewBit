vector<int> Solution::twoSum(const vector<int> &A, int target)
{
    vector<int> ans;
    unordered_map<int, int> m;
    int n = A.size();

    for (int i = 0; i < n; i++)
    {
        int curr = A[i];
        int j = target - curr;
        if (m.find(j) != m.end())
        {
            ans.push_back(m[j]);
            ans.push_back(i + 1);
            return ans;
        }
        if (m.find(curr) == m.end())
            m[curr] = i + 1;
    }

    return ans;
}


// https://www.interviewbit.com/problems/2-sum/