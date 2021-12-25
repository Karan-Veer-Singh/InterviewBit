vector<int> Solution::solve(vector<int> &A, int B)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> ans;

    for (int i = 0; i < A.size(); i++)
    {
        if (i < B)
        {
            pq.push(A[i]);
        }
        else if (A[i] > pq.top())
        {
            pq.pop();
            pq.push(A[i]);
        }
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}


// https://www.interviewbit.com/problems/k-largest-elements/