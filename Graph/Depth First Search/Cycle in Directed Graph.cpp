// DFS

bool detectCycle(int node, vector<int> &vis, vector<int> &path, vector<int> adj[])
{
    vis[node] = 1;
    path[node] = 1;

    for (auto ngbr : adj[node])
    {
        if (vis[ngbr] == 0)
        {
            if (detectCycle(ngbr, vis, path, adj))
                return true;
        }
        else if (path[ngbr] == 1)
        {
            return true;
        }
    }

    path[node] = 0;
    return false;
}

int Solution::solve(int V, vector<vector<int> > &B)
{
    vector<int> adj[V + 1];

    for (int i = 0; i < B.size(); i++)
        adj[B[i][0]].push_back(B[i][1]);

    vector<int> vis(V + 1, 0);
    vector<int> path(V + 1, 0);

    for (int i = 1; i <= V; i++)
        if (vis[i] == 0)
            if (detectCycle(i, vis, path, adj))
                return true;

    return false;
}

-------------------------------------------------------------------------- -
// BFS

int Solution::solve(int V, vector<vector<int> > &B)
{
    vector<int> adj[V + 1];

    for (int i = 0; i < B.size(); i++)
        adj[B[i][0]].push_back(B[i][1]);

    queue<int> q;
    vector<int> indegree(V + 1, 0);

    for (int i = 1; i <= V; i++)
        for (auto ngbr : adj[i])
            indegree[ngbr]++;

    for (int i = 1; i <= V; i++)
        if (indegree[i] == 0)
            q.push(i);

    int count = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;

        for (auto ngbr : adj[node])
        {
            indegree[ngbr]--;

            if (indegree[ngbr] == 0)
                q.push(ngbr);
        }
    }

    return (count == V) ? false : true;

}


--------------------------------------------------------------------------

// https://www.interviewbit.com/problems/cycle-in-directed-graph/