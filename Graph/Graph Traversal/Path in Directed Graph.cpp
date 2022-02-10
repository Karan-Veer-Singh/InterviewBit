bool checkPath(int node, int target, vector<int> &vis, vector<int> adj[])
{
    if (node == target)
        return true;

    vis[node] = 1;

    for (auto ngbr : adj[node])
    {
        if (vis[ngbr] == 0)
            if (checkPath(ngbr, target, vis, adj))
                return true;
    }

    return false;
}

int Solution::solve(int V, vector<vector<int> > &B)
{
    vector<int> adj[V + 1];

    for (int i = 0; i < B.size(); i++)
        adj[B[i][0]].push_back(B[i][1]);

    vector<int> vis(V + 1, 0);

    return checkPath(1, V, vis, adj);
}


// https://www.interviewbit.com/problems/path-in-directed-graph/