vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    priority_queue<pair<int, pair<int, int>>> pq;
    set<pair<int, int>> s;
    vector<int> ans;
    int n = A.size();

    pq.push({A[n - 1] + B[n - 1], {n - 1, n - 1}});
    s.insert({n - 1, n - 1});

    while (C--)
    {
        auto temp = pq.top();
        pq.pop();

        int element = temp.first;
        int aIndex = temp.second.first;
        int bIndex = temp.second.second;

        ans.push_back(element);

        if (aIndex > 0 && s.find({aIndex - 1, bIndex}) == s.end())
        {
            int nextElement = A[aIndex - 1] + B[bIndex];
            int newAIndex = aIndex - 1;
            int newBIndex = bIndex;;

            pq.push({nextElement, {newAIndex, newBIndex}});
            s.insert({newAIndex, newBIndex});
        }
        if (bIndex > 0 && s.find({aIndex, bIndex - 1}) == s.end())
        {
            int nextElement = A[aIndex] + B[bIndex - 1];
            int newAIndex = aIndex;
            int newBIndex = bIndex - 1;

            pq.push({nextElement, {newAIndex, newBIndex}});
            s.insert({newAIndex, newBIndex});
        }
    }

    return ans;
}


// https://www.interviewbit.com/problems/maximum-sum-combinations/