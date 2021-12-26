int Solution::solve(vector<vector<int> > &A)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < A.size(); i++)
        v.push_back({A[i][1], A[i][0]});

    sort(v.begin(), v.end());

    int ans = 1;
    int end = v[0].first;

    for (int i = 1; i < v.size(); i++)
    {
        int start = v[i].second;
        if (end < start)
        {
            ans++;
            end = v[i].first;
        }
    }

    return ans;
}


// https://www.interviewbit.com/problems/disjoint-intervals/