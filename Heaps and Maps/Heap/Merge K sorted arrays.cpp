vector<int> Solution::solve(vector<vector<int> > &A)
{
    typedef pair<int, pair<int, int>> node;
    priority_queue<node, vector<node>, greater<node>> pq;
    vector<int> ans;
    int k = A.size();

    for (int i = 0; i < k; i++)
        pq.push({A[i][0], {i, 0}});

    while (!pq.empty())
    {
        node temp = pq.top();
        pq.pop();

        int element = temp.first;
        int aIndex = temp.second.first;
        int eIndex = temp.second.second;

        ans.push_back(element);

        if (eIndex + 1 < A[aIndex].size())
            pq.push({A[aIndex][eIndex + 1], {aIndex, eIndex + 1}});
    }

    return ans;
}


// https://www.interviewbit.com/problems/merge-k-sorted-arrays/