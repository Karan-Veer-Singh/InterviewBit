int Solution::solve(int A, vector<int> &B, vector<int> &C)
{
    vector<int> adj[A + 1];
    vector<int> indegree(A + 1, 0);
    vector<bool> vis(A + 1, false);

    for (int i = 0; i < B.size(); i++)
    {
        int src = B[i];
        int dest = C[i];

        adj[src].push_back(dest);
        indegree[dest]++;
    }

    queue<int> q;
    int count = 0;

    for (int i = 1; i <= A; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            vis[i] = true;
            count++;
        }
    }

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto ngbr : adj[node])
        {
            if (vis[ngbr] == false)
            {
                indegree[ngbr]--;
                if (indegree[ngbr] == 0)
                {
                    q.push(ngbr);
                    vis[ngbr] = true;
                    count++;
                }
            }
        }
    }

    return (count == A);
}


// https://www.interviewbit.com/problems/possibility-of-finishing-all-courses-given-prerequisites/